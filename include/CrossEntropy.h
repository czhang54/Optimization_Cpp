/*
This header defines the Cross Entropy (CE) algorithm. 
*/

#include <iostream>

#include <Eigen/Dense>

#include <Algorithm.h>


namespace optimization{

    class CrossEntropy: public Algorithm
	{
		double quantile_  = 0.1; // Quantile parameter to select elite samples
		double smoothing_ = 0.2; // Smoothing parameter
		int num_elites_; // Number of elite samples (fixed)
		VectorXd model_mean_; // Mean of the model, updated at each iteration
		MatrixXd model_cov_; // Covariance matrix of the model, updated at each iteration

	public:

		/* Default trivial constructor */
		CrossEntropy() {}

		/* Constructor */
		explicit CrossEntropy(int num_iterations, int dim, int num_particles) 
			: Algorithm(num_iterations, dim, num_particles) {
				num_elites_ = static_cast<int>(num_particles*quantile_);
				model_mean_ = VectorXd::Constant(dim, 40);
				VectorXd cov = VectorXd::Constant(dim, 400);
				model_cov_ = cov.asDiagonal();
			}

		virtual MatrixXd run(const MatrixXd &X, int TI, double dt, std::default_random_engine &generator);

		void selectElites(const MatrixXd &X, RowVectorXd &h, MatrixXd &elites); 

		void updateParameters(MatrixXd &elites, RowVectorXd &weights);

		void generateNewSamples(MatrixXd &new_samples, std::default_random_engine &generator);



	};

}