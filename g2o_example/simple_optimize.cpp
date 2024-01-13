#include "g2o/core/sparse_optimizer.h"
#include "g2o/core/block_solver.h"
#include "g2o/core/factory.h"
#include "g2o/core/optimization_algorithm_levenberg.h"
#include "g2o/solvers/csparse/linear_solver_csparse.h"

#include "g2o/types/slam2d/vertex_se2.h"
#include "g2o/types/slam3d/vertex_se3.h"
// #include "g2o/types/slam3d/edge_se3.h"

G2O_USE_TYPE_GROUP(slam3d);
G2O_USE_TYPE_GROUP(slam2d);

#include <iostream>

using namespace std;
using namespace g2o;

#define MAXITERATION 10
int main()
{
    // create the linear solver
    BlockSolverX::LinearSolverType *linearSolver = new LinearSolverCSparse<BlockSolverX::PoseMatrixType>();

    // create the block solver on the top of the linear solver
    BlockSolverX *blockSolver = new BlockSolverX(linearSolver);

    // create the algorithm to carry out the optimization
    OptimizationAlgorithmLevenberg *optimizationAlgorithm = new OptimizationAlgorithmLevenberg(blockSolver);

    // create the optimizer
    SparseOptimizer optimizer;

    if (!optimizer.load("../dataset/manhattanOlson3500.g2o"))
    // if(!optimizer.load("../data/manhattanOlson3500.g2o"))
    {
        cout << "Error loading graph" << endl;
        return -1;
    }
    else
    {
        cout << "Loaded " << optimizer.vertices().size() << " vertices" << endl;
        cout << "Loaded " << optimizer.edges().size() << " edges" << endl;
    }

    // VertexSE2* firstRobotPose = dynamic_cast<VertexSE2*>(optimizer.vertex(0));
    VertexSE3 *firstRobotPose = dynamic_cast<VertexSE3 *>(optimizer.vertex(0));
    firstRobotPose->setFixed(true);

    optimizer.setAlgorithm(optimizationAlgorithm);
    optimizer.setVerbose(true);
    optimizer.initializeOptimization();
    cerr << "Optimizing ..." << endl;
    optimizer.optimize(MAXITERATION);
    cerr << "done." << endl;

    optimizer.save("../dataset/manhattanOlson3500_after.g2o");
    // optimizer.save("../data/manhattanOlson3500_after.g2o");
    optimizer.clear();

    return 0;
}
