#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

/****************************************************************************
 *                     xyz file analysis of molecules                       *
 *                                                                          *
 * This program takes in a set of molecular xyz coordinates and outputs     *
 * bond lengths, angles, torsions, out-of-planes, center of mass, and       *
 * moment of inertia.                                                       *
 *                                                                          *
 * No guarantees are made that the results of this program are correct      *
 * and the author assumes no liability for their reliability.               *
 *                                                                          *
 *                              Arin Avanoosyan                             *
 *                                                                          *
 *                                 12/23/2015                               *
 *                                 C++ version                              *
 ****************************************************************************/

// CONSTANTS
// 

// threshold beyond average of covalent radii 
const double bond_thresh = 1.2;

// conversion from radians to degrees and vice versa
const double rad2deg = 180.0 / M_PI;
const double deg2rad = M_PI / 180.0;

// threshold for degenerate principal moments of inertia (1 part per 10**n)
const int mom_thresh = 3;

// absolute threshold for moment of inertia difference
const double mom_min = pow(10, -mom_thresh);

// Planck's constant (J*s)
const double h = 6.62607e-34;

// avogadro's number (mol^-1)
const double na = 6.02214e23;

// speed of light(cm/s)
const double c = 2.99792e10;

// cartesian indices
const std::map<int, std::string> xyz = {{0, "X"}, {1, "Y"}, {2, "Z"}};

// covalent (or ionic) radii by atomic element (Angstroms)
const std::map<std::string, double> cov_rads = {
    {"H", 0.37}, {"C", 0.77}, {"O", 0.73}, {"N", 0.75}, {"F", 0.71},
    {"P", 1.10}, {"S", 1.03}, {"Cl", 0.99}, {"Br", 1.14}, {"I", 1.33}, {"He", 0.30},
    {"Ne", 0.84}, {"Ar", 1.00}, {"Li", 1.02}, {"Be", 0.27}, {"B", 0.88}, {"Na", 1.02},
    {"Mg", 0.72}, {"Al", 1.30}, {"Si", 1.18}, {"K", 1.38}, {"Ca", 1.00}, {"Sc", 0.75},
    {"Ti", 0.86}, {"V", 0.79}, {"Cr", 0.73}, {"Mn", 0.67}, {"Fe", 0.61}, {"Co", 0.64},
    {"Ni", 0.55}, {"Cu", 0.46}, {"Zn", 0.60}, {"Ga", 1.22}, {"Ge", 1.22}, {"As", 1.22},
    {"Se", 1.17}, {"Kr", 1.03}, {"X", 0.00}
};

// relative atomic masses of elements (in atomic mass units [amu])
const std::map<std::string, double> at_masses = {
    {"H", 1.00794}, {"C", 12.0107}, {"O", 15.9994}, {"N", 14.0067},
    {"F", 18.9984}, {"P", 30.9738}, {"S", 32.0650}, {"Cl", 35.4530}, {"Br", 79.9040},
    {"I", 126.904}, {"He", 4.00260}, {"Ne", 20.1797}, {"Ar", 39.9480}, {"Li", 6.94100},
    {"Be", 9.01218}, {"B", 10.8110}, {"Na", 22.9898}, {"Mg", 24.3050}, {"Al", 26.9815},
    {"Si", 28.0855}, {"K", 39.0983}, {"Ca", 40.0780}, {"Sc", 44.9559}, {"Ti", 47.8670},
    {"V", 50.9415}, {"Cr", 51.9961}, {"Mn", 54.9380}, {"Fe", 55.8450}, {"Co", 58.9332},
    {"Ni", 58.6934}, {"Cu", 63.5460}, {"Zn", 65 *                                 C++ version                              *
        .4090}, {"Ga", 69.7230}, {"Ge", 72.6400},
    {"As", 74.9216}, {"Se", 78.9600}, {"Kr", 83.7980}, {"X", 0.00000}
};

// Define a structure to hold geometry data
struct Geometry {
    std::vector<std::string> at_types;
    Eigen::MatrixXd coords;
};

// Define structures for molecular measurements
struct Bond {
    int n1, n2;
    double r12;
};

struct Angle {
    int n1, n2, n3;
    double a123;
};

struct Torsion {
    int n1, n2, n3, n4;
    double t1234;
};

struct OutOfPlane {
    int n1, n2, n3, n4;
    double o1234;
};

// IO FUNCTIONS

// Read file data into a 2D vector of strings
std::vector<std::vector<std::string>> get_file_string_array(const std::string& file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Error: file (" << file_name << ") not found!" << std::endl;
        exit(1);
    }
    
    std::vector<std::vector<std::string>> array;
    std::string line;
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string token;
        
        while (iss >> token) {
            tokens.push_back(token);
        }
        
        array.push_back(tokens);
    }
    
    file.close();
    return array;
}

// Read in geometry from xyz file
Geometry get_geom(const std::string& xyz_file_name) {
    auto xyz_array = get_file_string_array(xyz_file_name);
    int n_atoms = std::stoi(xyz_array[0][0]);
    
    Geometry geom;
    geom.at_types.resize(n_atoms);
    geom.coords.resize(n_atoms, 3);
    
    for (int i = 0; i < n_atoms; i++) {
        geom.at_types[i] = xyz_array[i+2][0];
        for (int j = 0; j < 3; j++) {
            geom.coords(i, j) = std::stod(xyz_array[i+2][j+1]);
        }
    }
    
    return geom;
}

// Input syntax and usage warnings
std::string get_inputs(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "\nUsage: geometry_analysis XYZ_FILE\n" << std::endl;
        std::cout << "  XYZ_FILE: coordinates of target molecule\n" << std::endl;
        exit(1);
    } else {
        std::string xyz_file_name = argv[1];
        std::string xyz_name = xyz_file_name.substr(xyz_file_name.find_last_of('/') + 1);
        xyz_name = xyz_name.substr(0, xyz_name.find_last_of('.'));
        std::cout << "\ngeometry analysis for " << xyz_name << "\n" << std::endl;
        return xyz_file_name;
    }
}

// Print geometry to screen
void print_geom(const Geometry& geom, const std::string& comment) {
    int n_atoms = geom.at_types.size();
    std::cout << n_atoms << "\n" << comment << std::endl;
    
    for (int i = 0; i < n_atoms; i++) {
        std::cout << std::left << std::setw(2) << geom.at_types[i];
        for (int j = 0; j < 3; j++) {
            std::cout << std::right << std::setw(13) << std::fixed << std::setprecision(6) << geom.coords(i, j);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Print bond graph to screen
void print_bond_graph(const Geometry& geom, const std::vector<std::vector<int>>& bond_graph, const std::string& comment) {
    int n_atoms = geom.at_types.size();
    std::cout << comment << std::endl;
    
    for (int i = 0; i < n_atoms; i++) {
        std::cout << std::right << std::setw(5) << i+1 << " " << std::left << std::setw(2) << geom.at_types[i] << " -";
        for (size_t j = 0; j < bond_graph[i].size(); j++) {
            std::cout << " " << bond_graph[i][j] + 1;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Print list of bond lengths to screen
void print_bonds(const Geometry& geom, const std::vector<Bond>& bonds) {
    int n_bonds = bonds.size();
    std::cout << n_bonds << " bond length(s) found (Angstrom)" << std::endl;
    
    if (n_bonds > 0) {
        std::cout << " atoms            elements         values" << std::endl;
    }
    
    for (int q = 0; q < n_bonds; q++) {
        int n1 = bonds[q].n1;
        int n2 = bonds[q].n2;
        double r12 = bonds[q].r12;
        
        std::string nstr = std::to_string(n1+1) + "-" + std::to_string(n2+1);
        std::string tstr = "(" + geom.at_types[n1] + "-" + geom.at_types[n2] + ") ";
        
        std::cout << " " << std::left << std::setw(15) << nstr << "  " << std::left << std::setw(13) 
                  << tstr << "    " << std::fixed << std::setprecision(4) << r12 << std::endl;
    }
    std::cout << std::endl;
}

// Print list of bond angles to screen
void print_angles(const Geometry& geom, const std::vector<Angle>& angles) {
    int n_angles = angles.size();
    std::cout << n_angles << " bond angle(s) found (degrees)" << std::endl;
    
    if (n_angles > 0) {
        std::cout << " atoms            elements         values" << std::endl;
    }
    
    for (int q = 0; q < n_angles; q++) {
        int n1 = angles[q].n1;
        int n2 = angles[q].n2;
        int n3 = angles[q].n3;
        double a123 = angles[q].a123;
        
        std::string nstr = std::to_string(n1+1) + "-" + std::to_string(n2+1) + "-" + std::to_string(n3+1);
        std::string tstr = "(" + geom.at_types[n1] + "-" + geom.at_types[n2] + "-" + geom.at_types[n3] + ") ";
        
        std::cout << " " << std::left << std::setw(15) << nstr << "  " << std::left << std::setw(13) 
                  << tstr << "   " << std::fixed << std::setprecision(3) << a123 << std::endl;
    }
    std::cout << std::endl;
}

// Print list of torsion angles to screen
void print_torsions(const Geometry& geom, const std::vector<Torsion>& torsions) {
    int n_torsions = torsions.size();
    std::cout << n_torsions << " torsion angle(s) found (degrees)" << std::endl;
    
    if (n_torsions > 0) {
        std::cout << " atoms            elements         values" << std::endl;
    }
    
    for (int q = 0; q < n_torsions; q++) {
        int n1 = torsions[q].n1;
        int n2 = torsions[q].n2;
        int n3 = torsions[q].n3;
        int n4 = torsions[q].n4;
        double t1234 = torsions[q].t1234;
        
        std::string nstr = std::to_string(n1+1) + "-" + std::to_string(n2+1) + "-" + 
                           std::to_string(n3+1) + "-" + std::to_string(n4+1);
        std::string tstr = "(" + geom.at_types[n1] + "-" + geom.at_types[n2] + "-" + 
                          geom.at_types[n3] + "-" + geom.at_types[n4] + ") ";
        
        std::cout << " " << std::left << std::setw(15) << nstr << "  " << std::left << std::setw(13) 
                  << tstr << "  " << std::fixed << std::setprecision(3) << t1234 << std::endl;
    }
    std::cout << std::endl;
}

// Print list of out-of-plane angles to screen
void print_outofplanes(const Geometry& geom, const std::vector<OutOfPlane>& outofplanes) {
    int n_outofplanes = outofplanes.size();
    std::cout << n_outofplanes << " out-of-plane angle(s) found (degrees)" << std::endl;
    
    if (n_outofplanes > 0) {
        std::cout << " atoms            elements         values" << std::endl;
    }
    
    for (int q = 0; q < n_outofplanes; q++) {
        int n1 = outofplanes[q].n1;
        int n2 = outofplanes[q].n2;
        int n3 = outofplanes[q].n3;
        int n4 = outofplanes[q].n4;
        double o1234 = outofplanes[q].o1234;
        
        std::string nstr = std::to_string(n1+1) + "-" + std::to_string(n2+1) + "-" + 
                           std::to_string(n3+1) + "-" + std::to_string(n4+1);
        std::string tstr = "(" + geom.at_types[n1] + "-" + geom.at_types[n2] + "-" + 
                          geom.at_types[n3] + "-" + geom.at_types[n4] + ") ";
        
        std::cout << " " << std::left << std::setw(15) << nstr << "  " << std::left << std::setw(13) 
                  << tstr << "  " << std::fixed << std::setprecision(3) << o1234 << std::endl;
    }
    std::cout << std::endl;
}

// Print center of mass coordinates
void print_com(const Eigen::Vector3d& com) {
    std::cout << "molecular center of mass (Angstrom)" << std::endl;
    std::cout << "        X             Y             Z" << std::endl << "  ";
    
    for (int p = 0; p < 3; p++) {
        std::cout << std::right << std::setw(13) << std::fixed << std::setprecision(6) << com(p);
    }
    std::cout << std::endl << std::endl;
}

// Print moment of inertia tensor
void print_moi(const Eigen::Matrix3d& moi) {
    std::cout << "molecular moment of inertia tensor (amu * A^2)" << std::endl;
    std::cout << "           X             Y             Z" << std::endl;
    
    for (int p = 0; p < 3; p++) {
        std::cout << std::left << std::setw(2) << xyz.at(p);
        for (int q = 0; q < 3; q++) {
            std::cout << std::right << std::setw(13) << std::fixed << std::setprecision(6) << moi(p, q);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Print principal moments of inertia (eigenvalues of tensor)
void print_prinmom(const Eigen::Vector3d& prinmom) {
    std::cout << "principal moments of inertia (amu * A^2)" << std::endl << "  ";
    
    for (int p = 0; p < 3; p++) {
        std::cout << std::right << std::setw(13) << std::fixed << std::setprecision(6) << prinmom(p);
    }
    std::cout << std::endl << std::endl;
}

// Print molecule type
void print_moltype(const std::string& moltype) {
    std::cout << "this molecule is " << moltype << std::endl << std::endl;
}

// Print rotational constants in mhz and wavenumber (cm^-1)
void print_rotfreq(const std::vector<double>& freq, const std::string& units) {
    std::cout << "rotational frequencies (" << units << ")" << std::endl << "  ";
    
    for (size_t p = 0; p < freq.size(); p++) {
        if (freq[p] < 0.1) {
            int precision = 3 - static_cast<int>(log10(freq[p]));
            std::cout << std::right << std::setw(13) << std::scientific << std::setprecision(precision) << freq[p];
        } else {
            int precision = 6 - static_cast<int>(log10(freq[p]));
            std::cout << std::right << std::setw(13) << std::fixed << std::setprecision(precision) << freq[p];
        }
    }
    std::cout << std::endl << std::endl;
}

// MATH FUNCTIONS

// Compare if two values are the same within specified threshold
bool are_same(double n1, double n2, int tol, double minval) {
    bool same = false;
    double nmax = std::max({std::abs(n1), std::abs(n2), std::abs(minval)});
    double comp = std::abs((n2 - n1) / nmax);
    
    if (comp <= pow(10, -tol)) {
        same = true;
    }
    return same;
}

// Calculate distance between two 3-d cartesian coordinates
double get_r12(const Eigen::Vector3d& coords1, const Eigen::Vector3d& coords2) {
    return (coords2 - coords1).norm();
}

// Calculate unit vector between to 3-d cartesian coordinates
Eigen::Vector3d get_u12(const Eigen::Vector3d& coords1, const Eigen::Vector3d& coords2) {
    double r12 = get_r12(coords1, coords2);
    return (coords2 - coords1) / r12;
}

// Calculate dot product between two unit vectors
double get_udp(const Eigen::Vector3d& uvec1, const Eigen::Vector3d& uvec2) {
    double udp = uvec1.dot(uvec2);
    return std::max(std::min(udp, 1.0), -1.0);
}

// Calculate unit cross product between two unit vectors
Eigen::Vector3d get_ucp(const Eigen::Vector3d& uvec1, const Eigen::Vector3d& uvec2) {
    Eigen::Vector3d ucp;
    double cos_12 = get_udp(uvec1, uvec2);
    double sin_12 = sqrt(1 - cos_12 * cos_12);
    
    ucp(0) = (uvec1(1) * uvec2(2) - uvec1(2) * uvec2(1)) / sin_12;
    ucp(1) = (uvec1(2) * uvec2(0) - uvec1(0) * uvec2(2)) / sin_12;
    ucp(2) = (uvec1(0) * uvec2(1) - uvec1(1) * uvec2(0)) / sin_12;
    
    return ucp;
}

// Calculate angle between three 3-d cartesian coordinates
double get_a123(const Eigen::Vector3d& coords1, const Eigen::Vector3d& coords2, const Eigen::Vector3d& coords3) {
    Eigen::Vector3d u21 = get_u12(coords2, coords1);
    Eigen::Vector3d u23 = get_u12(coords2, coords3);
    double dp2123 = get_udp(u21, u23);
    return rad2deg * acos(dp2123);
}

// Calculate torsion angle between four 3-d cartesian coordinates
double get_t1234(const Eigen::Vector3d& coords1, const Eigen::Vector3d& coords2, 
                const Eigen::Vector3d& coords3, const Eigen::Vector3d& coords4) {
    Eigen::Vector3d u21 = get_u12(coords2, coords1);
    Eigen::Vector3d u23 = get_u12(coords2, coords3);
    Eigen::Vector3d u32 = get_u12(coords3, coords2);
    Eigen::Vector3d u34 = get_u12(coords3, coords4);
    
    Eigen::Vector3d u21c23 = get_ucp(u21, u23);
    Eigen::Vector3d u32c34 = get_ucp(u32, u34);
    
    double dp = get_udp(u21c23, u32c34);
    double sign = 2.0 * static_cast<double>(get_udp(u21c23, u34) < 0) - 1.0;
    
    return rad2deg * sign * acos(dp);
}

// Calculate out-of-plane (improper torsion) angle between four 3-d cartesian coordinates
double get_o1234(const Eigen::Vector3d& coords1, const Eigen::Vector3d& coords2, 
                const Eigen::Vector3d& coords3, const Eigen::Vector3d& coords4) {
    Eigen::Vector3d u42 = get_u12(coords4, coords2);
    Eigen::Vector3d u43 = get_u12(coords4, coords3);
    Eigen::Vector3d u41 = get_u12(coords4, coords1);
    
    Eigen::Vector3d u42c43 = get_ucp(u42, u43);
    double dp = get_udp(u42c43, u41);
    
    return rad2deg * asin(dp);
}

// Translate coordinates by a defined vector and scale factor
Geometry translate_coords(const Geometry& geom, const Eigen::Vector3d& vector, double scale) {
    Geometry new_geom = geom;
    int n_atoms = geom.coords.rows();
    
    for (int i = 0; i < n_atoms; i++) {
        for (int j = 0; j < 3; j++) {
            new_geom.coords(i, j) += scale * vector(j);
        }
    }
    
    return new_geom;
}

// Calculate center of mass of a set of atoms
Eigen::Vector3d get_com(const Geometry& geom) {
    int n_atoms = geom.at_types.size();
    Eigen::Vector3d com = Eigen::Vector3d::Zero();
    double mass = 0.0;
    
    for (int i = 0; i < n_atoms; i++) {
        double at_mass = at_masses.at(geom.at_types[i]);
        mass += at_mass;
        
        for (int j = 0; j < 3; j++) {
            com(j) += at_mass * geom.coords(i, j);
        }
    }
    
    com /= mass;
    return com;
}

// Calculate moment of inertia tensor for a set of atoms
Eigen::Matrix3d get_moi(const Geometry& geom) {
    int n_atoms = geom.at_types.size();
    Eigen::Matrix3d moi = Eigen::Matrix3d::Zero();
    
    for (int i = 0; i < n_atoms; i++) {
        double at_mass = at_masses.at(geom.at_types[i]);
        
        for (int p = 0; p < 3; p++) {
            for (int q = 0; q < 3; q++) {
                if (p == q) {
                    int r = (p + 1) % 3;
                    int s = (p + 2) % 3;
                    moi(p, p) += at_mass * (pow(geom.coords(i, r), 2) + pow(geom.coords(i, s), 2));
                } else {
                    moi(p, q) += -at_mass * geom.coords(i, p) * geom.coords(i, q);
                }
            }
        }
    }
    
    return moi;
}

// Calculate principal moments of inertia (eigenvalues of tensor)
Eigen::Vector3d get_prinmom(const Eigen::Matrix3d& moi) {
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> solver(moi);
    return solver.eigenvalues();
}

// Calculate rotational frequencies in MHz and wavenumbers (cm^-1)
std::pair<std::vector<double>, std::vector<double>> get_rotfreq(const Eigen::Vector3d& prinmom) {
    std::vector<double> freqcm1, freqmhz;
    
    for (int p = 0; p < 3; p++) {
        bool iszero = are_same(prinmom(p), 0.0, mom_thresh, mom_min);
        bool degen = (p > 0 && are_same(prinmom(p-1), prinmom(p), mom_thresh, mom_min));
        
        if (iszero || degen) {
            continue;
        }
        
        double mhz = h / (8 * pow(M_PI, 2) * prinmom(p));
        mhz *= pow(1e10, 2) * na * 1e3 * 1e-6;
        
        double cm1 = mhz / c * 1e6;
        
        freqmhz.push_back(mhz);
        freqcm1.push_back(cm1);
    }
    
    return {freqmhz, freqcm1};
}

// Rotate molecule to inertial frame of principal moments
Geometry get_inertial_coords(const Geometry& geom, const Eigen::Matrix3d& moi) {
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> solver(moi);
    Eigen::Vector3d moi_eigvals = solver.eigenvalues();
    Eigen::Matrix3d moi_eigvecs = solver.eigenvectors();
    
    Geometry new_geom = geom;
    Eigen::MatrixXd coords = geom.coords * moi_eigvecs;
    new_geom.coords = coords;
    
    Eigen::Matrix3d new_moi = get_moi(new_geom);
    
    std::vector<int> order = {0, 1, 2};
    for (int p = 0; p < 3; p++) {
        for (int q = p + 1; q < 3; q++) {
            if (new_moi(p, p) < new_moi(q, q)) {
                std::swap(order[p], order[q]);
            }
        }
    }
    
    Eigen::Matrix3d moveaxes = Eigen::Matrix3d::Zero();
    for (int p = 0; p < 3; p++) {
        moveaxes(p, order[p]) = 1.0;
    }
    
    new_geom.coords = coords * moveaxes;
    return new_geom;
}

// TOPOLOGY FUNCTIONS

// Build graph of which atoms are covalently bonded
std::vector<std::vector<int>> get_bond_graph(const Geometry& geom) {
    int n_atoms = geom.at_types.size();
    std::vector<std::vector<int>> bond_graph(n_atoms);
    
    for (int i = 0; i < n_atoms; i++) {
        double covrad1 = cov_rads.at(geom.at_types[i]);
        
        for (int j = i + 1; j < n_atoms; j++) {
            double covrad2 = cov_rads.at(geom.at_types[j]);
            double thresh = bond_thresh * (covrad1 + covrad2);
            
            Eigen::Vector3d coords1 = geom.coords.row(i);
            Eigen::Vector3d coords2 = geom.coords.row(j);
            double r12 = get_r12(coords1, coords2);
            
            if (r12 < thresh) {
                bond_graph[i].push_back(j);
                bond_graph[j].push_back(i);
            }
        }
    }
    
    return bond_graph;
}

// Determine atoms which are covalently bonded from bond graph
std::vector<Bond> get_bonds(const Geometry& geom, const std::vector<std::vector<int>>& bond_graph) {
    int n_atoms = geom.at_types.size();
    std::vector<Bond> bonds;
    
    for (int i = 0; i < n_atoms; i++) {
        for (size_t a = 0; a < bond_graph[i].size(); a++) {
            int j = bond_graph[i][a];
            
            if (i < j) {
                Eigen::Vector3d coords1 = geom.coords.row(i);
                Eigen::Vector3d coords2 = geom.coords.row(j);
                double r12 = get_r12(coords1, coords2);
                bonds.push_back({i, j, r12});
            }
        }
    }
    
    return bonds;
}

// Determine atoms which form a bond angle from bond graph
std::vector<Angle> get_angles(const Geometry& geom, const std::vector<std::vector<int>>& bond_graph) {
    int n_atoms = geom.at_types.size();
    std::vector<Angle> angles;
    
    for (int j = 0; j < n_atoms; j++) {
        int n_jbonds = bond_graph[j].size();
        
        for (int a = 0; a < n_jbonds; a++) {
            int i = bond_graph[j][a];
            
            for (int b = a + 1; b < n_jbonds; b++) {
                int k = bond_graph[j][b];
                
                Eigen::Vector3d coords1 = geom.coords.row(i);
                Eigen::Vector3d coords2 = geom.coords.row(j);
                Eigen::Vector3d coords3 = geom.coords.row(k);
                
                double a123 = get_a123(coords1, coords2, coords3);
                angles.push_back({i, j, k, a123});
            }
        }
    }
    
    // Sort angles by first atom index
    std::sort(angles.begin(), angles.end(), 
        [](const Angle& a, const Angle& b) { return a.n1 < b.n1; });
    
    return angles;
}

// Determine atoms which form torsion angles from bond graph
std::vector<Torsion> get_torsions(const Geometry& geom, const std::vector<std::vector<int>>& bond_graph) {
    int n_atoms = geom.at_types.size();
    std::vector<Torsion> torsions;
    
    for (int j = 0; j < n_atoms; j++) {
        int n_jbonds = bond_graph[j].size();
        
        for (int a = 0; a < n_jbonds; a++) {
            int k = bond_graph[j][a];
            
            if (k < j) continue;
            
            int n_kbonds = bond_graph[k].size();
            
            for (int b = 0; b < n_jbonds; b++) {
                int i = bond_graph[j][b];
                
                if (i == k) continue;
                
                for (int c = 0; c < n_kbonds; c++) {
                    int l = bond_graph[k][c];
                    
                    if (l == j || l == i) continue;
                    
                    Eigen::Vector3d coords1 = geom.coords.row(i);
                    Eigen::Vector3d coords2 = geom.coords.row(j);
                    Eigen::Vector3d coords3 = geom.coords.row(k);
                    Eigen::Vector3d coords4 = geom.coords.row(l);
                    
                    double t1234 = get_t1234(coords1, coords2, coords3, coords4);
                    torsions.push_back({i, j, k, l, t1234});
                }
            }
        }
    }
    
    // Sort torsions by first atom index
    std::sort(torsions.begin(), torsions.end(), 
        [](const Torsion& a, const Torsion& b) { return a.n1 < b.n1; });
    
    return torsions;
}

// Determine atoms which form out-of-plane angles from bond graph
std::vector<OutOfPlane> get_outofplanes(const Geometry& geom, const std::vector<std::vector<int>>& bond_graph) {
    int n_atoms = geom.at_types.size();
    std::vector<OutOfPlane> outofplanes;
    
    for (int l = 0; l < n_atoms; l++) {
        int n_lbonds = bond_graph[l].size();
        
        for (int a = 0; a < n_lbonds; a++) {
            int i = bond_graph[l][a];
            
            for (int b = 0; b < n_lbonds; b++) {
                int j = bond_graph[l][b];
                
                if (i == j) continue;
                
                for (int c = b + 1; c < n_lbonds; c++) {
                    int k = bond_graph[l][c];
                    
                    if (i == k) continue;
                    
                    Eigen::Vector3d coords1 = geom.coords.row(i);
                    Eigen::Vector3d coords2 = geom.coords.row(j);
                    Eigen::Vector3d coords3 = geom.coords.row(k);
                    Eigen::Vector3d coords4 = geom.coords.row(l);
                    
                    double o1234 = get_o1234(coords1, coords2, coords3, coords4);
                    outofplanes.push_back({i, j, k, l, o1234});
                }
            }
        }
    }
    
    // Sort outofplanes by first atom index
    std::sort(outofplanes.begin(), outofplanes.end(), 
        [](const OutOfPlane& a, const OutOfPlane& b) { return a.n1 < b.n1; });
    
    return outofplanes;
}

// Determine molecule type based on principal moments of inertia
std::string get_moltype(const Geometry& geom, const Eigen::Vector3d& prinmom) {
    bool same12 = are_same(prinmom(0), prinmom(1), mom_thresh, mom_min);
    bool same13 = are_same(prinmom(0), prinmom(2), mom_thresh, mom_min);
    bool same23 = are_same(prinmom(1), prinmom(2), mom_thresh, mom_min);
    bool onezero = are_same(prinmom(0), 0.0, mom_thresh, mom_min);
    bool allzero = are_same(prinmom(2), 0.0, mom_thresh, mom_min);
    
    std::string moltype;
    if (allzero) {
        moltype = "monatomic";
    } else if (onezero) {
        moltype = "linear";
    } else if (same13) {
        moltype = "a spherical top";
    } else if (same12 || same23) {
        moltype = "a symmetric top";
    } else {
        moltype = "an asymmetric top";
    }
    
    return moltype;
}

int main(int argc, char* argv[]) {
    std::string xyz_file_name = get_inputs(argc, argv);
    Geometry geom = get_geom(xyz_file_name);
    auto bond_graph = get_bond_graph(geom);
    
    auto bonds = get_bonds(geom, bond_graph);
    auto angles = get_angles(geom, bond_graph);
    auto torsions = get_torsions(geom, bond_graph);
    auto outofplanes = get_outofplanes(geom, bond_graph);
    auto com = get_com(geom);
    
    print_geom(geom, "initial geometry");
    print_bonds(geom, bonds);
    print_angles(geom, angles);
    print_torsions(geom, torsions);
    print_outofplanes(geom, outofplanes);
    print_com(com);
    
    Geometry com_geom = translate_coords(geom, com, -1.0);
    print_geom(com_geom, "center of mass translated geometry");
    
    auto moi = get_moi(com_geom);
    auto prinmom = get_prinmom(moi);
    auto moltype = get_moltype(com_geom, prinmom);
    auto [rotmhz, rotcm1] = get_rotfreq(prinmom);
    
    print_moi(moi);
    print_prinmom(prinmom);
    print_moltype(moltype);
    print_rotfreq(rotmhz, "MHz");
    print_rotfreq(rotcm1, "cm^-1");
    
    Geometry moi_geom = get_inertial_coords(com_geom, moi);
    print_geom(moi_geom, "principal moment aligned geometry");
    
    std::cout << "geometry analysis completed successfully" << std::endl << std::endl;
    
    return 0;
}
