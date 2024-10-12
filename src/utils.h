#ifndef UTILS_H
#define UTILS_H

#include <Eigen/Dense>
#include <sstream>
#include <QString>

namespace Utils {
QString matrixToString(const Eigen::MatrixXd &m) {
    std::stringstream ss;
    ss << m;
    return QString::fromStdString(ss.str());
}
}

#endif // UTILS_H
