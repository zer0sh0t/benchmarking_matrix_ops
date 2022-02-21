#include <vector>
#include <iomanip>
#include <chrono>
#include <numeric>
#include <iostream>
#include "Eigen/Core"

// get a randomly generated matrix
Eigen::MatrixXd get_rand_mat(int r, int c)
{
    double min = -100000.0;
    double max = 100000.0;
    double range = max - min;
    Eigen::MatrixXd m = Eigen::MatrixXd::Random(r, c);
    m = (m + Eigen::MatrixXd::Constant(r, c, 1.0)) * range / 2.0;
    m = (m + Eigen::MatrixXd::Constant(r, c, min));
    return m;
}

double benchmark_op(int row, int col, char op, int iters)
{
    std::vector<double> op_times;
    for (int i = 0; i < iters; i++)
    {
        srand(time(NULL));
        Eigen::MatrixXd a = get_rand_mat(row, col), b = get_rand_mat(row, col), c(row, col);
        if (op == '+')
        {
            auto start = std::chrono::high_resolution_clock::now();
            c = a + b;
            auto end = std::chrono::high_resolution_clock::now();
            double time = std::chrono::duration<double, std::milli>(end - start).count();
            op_times.push_back(time);
        }
        else if (op == '*')
        {
            auto start = std::chrono::high_resolution_clock::now();
            c = a * b;
            auto end = std::chrono::high_resolution_clock::now();
            double time = std::chrono::duration<double, std::milli>(end - start).count();
            op_times.push_back(time);
        }
        else if (op == '-')
        {
            auto start = std::chrono::high_resolution_clock::now();
            c = a - b;
            auto end = std::chrono::high_resolution_clock::now();
            double time = std::chrono::duration<double, std::milli>(end - start).count();
            op_times.push_back(time);
        }
        else if (op == '/')
        {
            auto start = std::chrono::high_resolution_clock::now();
            c = a.array() / b.array();
            auto end = std::chrono::high_resolution_clock::now();
            double time = std::chrono::duration<double, std::milli>(end - start).count();
            op_times.push_back(time);
        }
        else if (op == '.')
        {
            auto start = std::chrono::high_resolution_clock::now();
            c = a.matrix() * b.matrix();
            auto end = std::chrono::high_resolution_clock::now();
            double time = std::chrono::duration<double, std::milli>(end - start).count();
            op_times.push_back(time);
        }
    }
    double avg = std::accumulate(op_times.begin(), op_times.end(), 0.0) / op_times.size();
    return avg;
}

int main(int argc, char **argv)
{
    int row = atoi(argv[1]), col = atoi(argv[2]), iters = atoi(argv[3]);
    std::vector<char> ops = {'+', '*', '-', '/', '.'};
    std::cout << std::fixed << std::setprecision(7);
    std::cout << "---------------------------------------" << '\n';
    std::cout << "eigen results:\n" << '\n';
    for (char op: ops)
    {
        double op_time = benchmark_op(row, col, op, iters);
        std::cout << "op: " << op << '\n' << "time taken: " << op_time * 0.001 << " secs" << '\n' << '\n';
    }
    std::cout << "---------------------------------------\n" << '\n';
    return 0;
}
