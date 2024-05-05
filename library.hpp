#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <chrono>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <math.h>

#define PARAMS_FILE "params.txt"
#define BEST_PARAMS_FILE "best_params.txt"
#define INPUT_FILE "input.txt"
#define unormap unordered_map
#define endl "\n"
#define LL long long
#define ULL unsigned long long
#define LD long double
#define INF 1e16

using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 gen(seed);

struct ABC_params 
{
    /*
        Objective:
            A struct responsible for storing parameters for the ABC algorithm.

        Attributes:
            cycles_limit: Maximum number of cycles.
            employed_limit: Maximum number of employed bees.
            colony_size: Size of the colony.
            scout_percent: Percentage of scouts.
            onlooker_percent: Percentage of onlooker bees.
            employed_percent: Percentage of employed bees.
			verbose = Defines whether to activate the verbose.
    */

    int cycles_limit;
    int employed_limit;
    int colony_size;
    double scout_percent;
    double onlooker_percent;
    double employed_percent;
	bool verbose;

    ABC_params() 
    {
        /*
            Objective:
                Default constructor initializing parameters with default values.
        */
        cycles_limit = 10000;
        employed_limit = 500;
        colony_size = 200;
        scout_percent = 0.4;
        onlooker_percent = 0.2;
        employed_percent = 0.8;
		verbose = 0;
    }
};

struct ACO_params
{
    /*
        Objective:
            A struct responsible for storing parameters for the ACO algorithm.

        Attributes:
            ants: Number of ants to be used in the algorithm.
            max_generations: Maximum number of generations.
            alpha: Alpha parameter for pheromone influence.
            beta: Beta parameter for heuristic influence.
            decay: Decay rate for pheromones.
            fix_init: Initial value for fixing the best route.
            max_opt_it: Maximum number of optimization iterations.
            local_search: Indicates whether local search should be performed.
            verbose: Indicates whether verbose output should be enabled.
    */

   	int ants;
	int max_generations;
	LD alpha;
	LD beta;
	LD decay;
	int fix_init;
	int max_opt_it;
	bool local_search;
	bool verbose;

	ACO_params()
	{
		/*
            Objective:
                Default constructor initializing parameters with default values.
        */
	   
		fix_init = -1;
		ants = 10;
		max_generations = 100; 
		alpha = 1; 
		beta = 2; 
		decay = 0.05; 
		local_search = true;
		verbose = true;
	}
};

struct grasp_params
{
	/*
        Objective:
            A struct responsible for storing parameters for the grasp algorithm.

        Attributes:
            l - Number of iterations (exchanges) to be performed on the current solution.
            alpha - Greed parameter for building solutions.
			cont_alpha - Count how many times alpha_i was selected.
			p_alpha - Probability of selecting an alpha_i.
			solution_alpha - Sum of solutions generated by alpha_i.
			beta - Value used as a criterion to determine when to update the probabilities.
			verbose = Defines whether to activate the verbose.
    */

	int l;
    int m;
    vector<int> cont_alpha;
    vector<double> p_alpha;
    vector<double> solution_alpha;
    vector<double> alpha;
    int beta;
	bool verbose;

	grasp_params()
	{
		/*
            Objective:
                Default constructor initializing parameters with default values.
        */
	   
		l = 1000;
		m = 5;
		cont_alpha.assign(m, 0);
		p_alpha.assign(m, 1.0 / m);
		solution_alpha.assign(m, 0.0);
		alpha = {0.1, 0.2, 0.3, 0.4, 0.5};
		beta = 4;
		verbose = 0;
	}
};

struct annealing_params
{
	/*
        Objective:
            A struct responsible for storing parameters for the annealing algorithm.

        Attributes:
            t0 - Initial temperature.
            tf - Final temperature.
            l - Number of iterations (exchanges) to be performed on the current solution.
            alpha - Temperature variation rate.
    */

	LD t0;
    LD tf;
    int l;
    LD alpha;

	annealing_params()
	{
		/*
            Objective:
                Default constructor initializing parameters with default values.
        */
	   
		t0 = 10000;
		tf = 0.01;
		l = 1000;
		alpha = 0.9;
	}
};

struct GA_Params
{
	/*
		Objective:
			Class aimed at defining the parameters that will be used in the genetic algorithm.

		Attributes:
			max_generations = Maximum number of generations.
			max_population = Maximum number of genes in the population.
			opt_range = Defines the probability of a gene being selected in the opt_range.
			opt_path_swap_it = Defines the number of simulations in the path optimizer.
			tx_elite = Defines the elitism rate in the population.
			verbose = Defines whether to activate the verbose.
			simple_verbose = Defines whether or not to activate the simple_verbose.
			alpha = Percentage of the parent gene relative to the mother's gene.
			balance = Defines in relation to the good percentage of the population that will be used for the new generation (0 defines as no elitism for generation).
			tx_mutation_AHCAVG = Defines the mutation rate in the arithmetic_average.
			fix_init = Defines whether there will be an initial number as fixed (-1 defines as not existing).
			P_value = Defines how many parents were considered.
			P_limiar = Defines the minimum quantity required for the city and to appear in the same position as the parents.
			cross_active = Stores which crossovers are active ("BCR" -> Best Cost Route crossover, "AHCAVG" -> Arithmetic Average *disabled*, "ER" -> Edge Recombination crossover, "VR" -> Voting Recombination Crossover , "PMX" -> PMX Crossover).
	*/

	int max_generations;
	int max_population;
	int opt_range;
	int opt_path_swap_it;
	int tx_elite;
	bool verbose;
	bool simple_verbose;
	int alpha;
	int balance;
	int tx_mutation_AHCAVG;
	int fix_init;
	int P_value;
	int repetition_limit;// *disabled*
	int P_limiar;
	vector<int> cross_active;

	GA_Params()
	{
		tx_elite = 50;
		verbose = 0;
		simple_verbose = 1;
		fix_init = -1;
		max_generations = 3000;
		max_population = 23;
		verbose = false;
		tx_mutation_AHCAVG =  0;
		balance = 0;
		opt_range = 60;
		repetition_limit = 200;
		P_value = 20;
		P_limiar = 3;
		opt_path_swap_it = 200;
		alpha = 10;
		cross_active = { 15, 0, 0, 0, 0};
	}

};

class params
{
	/*
		Objective:
			This structure is responsible for storing the parameters of the selected algorithm and the settings related to its execution.

		Attributes:
			markdown: Indicated markdown or not.
			hybrid: Vector indicating which hybrid algorithms are activated.
			metrics: Vector indicating which performance metrics are activated.
			ann_p: Annealing parameters.
			grasp_p: GRASP parameters.
			abc_p: ABC parameters.
			ga_p: Genetic Algorithm parameters.
			aco_p: Ant Colony Optimization parameters.
	*/

public:
	bool markdown;
	vector<bool> hybrid;
	vector<bool> metrics;
	annealing_params ann_p;
	grasp_params grasp_p;
	ABC_params abc_p;
	GA_Params ga_p;
	ACO_params aco_p;

	params()
	{
		hybrid.assign(5, 0);
	}

	params(string source)
	{
		/*
			Objective:
				An alternate constructor that allows initializing the parameters from a text file.

			Parameters:
				- source: Path to the file containing the parameters.
		*/

		hybrid.assign(5, 0);
		metrics.assign(3, 0);
		ifstream control_params(source);
		string in_param;

		while (control_params >> in_param)
		{
			if (in_param == "genetic") 
			{
				hybrid[0] = true;
				params::genetic_params(control_params);
			}

			if (in_param == "annealing")
			{
				hybrid[1] = true;
				params::ann_params(control_params);
			}

			if (in_param == "grasp")
			{
				hybrid[2] = true;
				params::grasp_params(control_params);
			}
			
			if (in_param == "aco")
			{
				hybrid[3] = true;
				params::aco_params(control_params);
			}

			if (in_param == "abc")
			{
				hybrid[4] = true;
				params::abc_params(control_params);
			}

			if (in_param == "MAE")
			{
				metrics[0] = 1;
			}

			if (in_param == "MSE")
			{
				metrics[1] = 1;
			}

			if (in_param == "R^2")
			{
				metrics[2] = 1;
			}

			if (in_param == "output_markdown")
			{
				markdown = true;
			}
		}
	}
	
	void genetic_params(ifstream& control_params)
	{
		/*
			Objective:
				Parse and set the parameters for the genetic algorithm from a file.

			Parameters:
				- control_params: Reference to the ifstream containing the parameter values.
		*/

		string in_param;
		int value;

		while (control_params >> in_param && in_param != "end")
		{
			if (in_param == "genetic.tx_elite")
			{
				control_params >> value;
				if (value > 1 && value < 101)
					ga_p.tx_elite = value;
				continue;
			}

			if (in_param == "genetic.max_generations")
			{
				control_params >> value;
				if (value > 0)
					ga_p.max_generations = value;
				continue;
			}

			if (in_param == "genetic.max_population")
			{
				control_params >> value;
				if (value >= 10)
					ga_p.max_population = value;
				continue;
			}

			if (in_param == "genetic.opt_range")
			{
				control_params >> value;
				if (ga_p.opt_range >= 0 && ga_p.opt_range <= 100)
					ga_p.opt_range = value;
				continue;
			}

			if (in_param == "genetic.opt_path_swap_it")
			{
				control_params >> value;
				if (value >= 0)
				{
					ga_p.opt_path_swap_it = value;
				}
				continue;
			}
			
			if (in_param == "genetic.verbose")
			{
				control_params >> value;
				ga_p.verbose = value;
				continue;
			}

			if (in_param == "genetic.simple_verbose")
			{
				control_params >> value;
				ga_p.simple_verbose = value;
				continue;
			}

			if (in_param == "genetic.alpha")
			{
				control_params >> value;
				if (ga_p.balance >= 0 && ga_p.balance <= 100)
				{
					ga_p.alpha = value;
				}
				continue;
			}

			if (in_param == "genetic.balance")
			{
				control_params >> value;
				if (ga_p.balance >= 0 && ga_p.balance < 4)
					ga_p.balance = value;

				continue;
			}

			if (in_param == "genetic.tx_mutation_AHCAVG")
			{
				control_params >> value;
				if (ga_p.tx_mutation_AHCAVG >= 0 && ga_p.tx_mutation_AHCAVG < 100)
					ga_p.tx_mutation_AHCAVG = value;
				continue;
			}

			if (in_param == "genetic.fix_init")
			{
				control_params >> value;
				if (value >= -1)
					ga_p.fix_init = value;
				continue;
			}

			if (in_param == "genetic.P_value")
			{
				control_params >> value;
				if(ga_p.P_value > 1)
					ga_p.P_value = value;
				continue;
			}

			if (in_param == "genetic.P_limiar")
			{
				control_params >> value;
				if (value > 0)
					ga_p.P_limiar = value;
				continue;
			}

			if (in_param == "genetic.cross_active.BCR")
			{
				control_params >> value;
				if(value>=0 && value<=100)
					ga_p.cross_active[0] = value;
				continue;
			}

			if (in_param == "genetic.cross_active.AHCAVG")
			{
				control_params >> value;
				if(value>=0 && value<=100)
					ga_p.cross_active[1] = value;
				continue;
			}

			if (in_param == "genetic.cross_active.ER")
			{
				control_params >> value;
				if(value>=0 && value<=100)
					ga_p.cross_active[2] = value;
				continue;
			}

			if (in_param == "genetic.cross_active.VR")
			{
				control_params >> value;
				if(value>=0 && value<=100)
					ga_p.cross_active[3] = value;
				continue;
			}
			
			if (in_param == "genetic.cross_active.PMX")
			{
				control_params >> value;
				if(value>=0 && value<=100)
					ga_p.cross_active[4] = value;
				continue;
			}
		}

		ga_p.P_value = max(0,min(ga_p.P_value, ga_p.max_population));
		ga_p.P_limiar = max(0,min(ga_p.P_limiar, ga_p.P_value));
		ga_p.tx_elite = (ga_p.tx_elite*ga_p.max_population)/100;
	}

	void aco_params(ifstream& control_params)
	{
		/*
			Objective:
				Parse and set the parameters for the Ant Colony Optimization algorithm from a file.

			Parameters:
				- control_params: Reference to the ifstream containing the parameter values.
		*/

		string in_param;
		int value;
		LD value_double;

		while (control_params >> in_param && in_param != "end")
		{
			if (in_param == "aco.verbose")
			{
				control_params >> value;
				aco_p.verbose = value;
				continue;
			}

			if (in_param == "aco.local_search")
			{
				control_params >> value;
				aco_p.local_search = value;
				continue;
			}

			if (in_param == "aco.max_opt_it")
			{
				control_params >> value;
				if (value>0)
					aco_p.max_opt_it = value;
				continue;
			}

			if (in_param == "aco.fix_init")
			{
				control_params >> value;
				if (value >= -1)
					aco_p.max_opt_it = value;
				continue;
			}

			if (in_param == "aco.decay")
			{
				control_params >> value_double;
				if (value_double>0)
					aco_p.decay = value_double;
				continue;
			}

			if (in_param == "aco.ants")
			{
				control_params >> value;
				if (value>0)
					aco_p.ants = value;
				continue;
			}

			if (in_param == "aco.max_generations")
			{
				control_params >> value;
				if (value>0)
					aco_p.max_generations = value;
				continue;
			}

			if (in_param == "aco.alpha")
			{
				control_params >> value_double;
				if (value_double>0)
					aco_p.alpha = value_double;
				continue;
			}

			if (in_param == "aco.beta")
			{
				control_params >> value_double;
				if (value_double>0)
					aco_p.beta = value_double;
				continue;
			}
		}
	}

	void abc_params(ifstream& control_params)
	{
		/*
			Objective:
				Parse and set the parameters for the Ant Colony Optimization algorithm from a file.

			Parameters:
				- control_params: Reference to the ifstream containing the parameter values.
		*/

		string in_param;
		int value;
		LD value_double;

		while (control_params >> in_param && in_param != "end")
		{
			
			if (in_param == "abc.cycles_limit")
			{
				control_params >> value;
				if (value > 1)
					abc_p.cycles_limit = value;
				continue;
			}

			if (in_param == "abc.employed_limit")
			{
				control_params >> value;
				if (value > 1)
					abc_p.employed_limit = value;
				continue;
			}
			
			if (in_param == "abc.colony_size")
			{
				control_params >> value;
				if (value > 1)
					abc_p.colony_size = value;
				continue;
			}
			
			if (in_param == "abc.scout_percent")
			{
				control_params >> value_double;
				if (value_double > 1)
					abc_p.scout_percent = value_double;
				continue;
			}
			
			if (in_param == "abc.onlooker_percent")
			{
				control_params >> value_double;
				if (value_double > 1)
					abc_p.onlooker_percent = value_double;
				continue;
			}
			
			if (in_param == "abc.employed_percent")
			{
				control_params >> value_double;
				if (value_double > 1)
					abc_p.employed_percent = value_double;
				continue;
			}
		}
	}

	void ann_params(ifstream& control_params)
	{
		/*
			Objective:
				Parse and set the parameters for the Annealing algorithm from a file.

			Parameters:
				- control_params: Reference to the ifstream containing the parameter values.
		*/

		string in_param;
		int value;
		LD value_double;

		while (control_params >> in_param && in_param != "end")
		{
			if (in_param == "annealing.t0")
			{
				control_params >> value_double;
				if (value_double > 1)
					ann_p.t0 = value_double;
				continue;
			}

			if (in_param == "annealing.tf")
			{
				control_params >> value_double;
				if (value_double > 1)
					ann_p.tf = value_double;
				continue;
			}
			
			if (in_param == "annealing.l")
			{
				control_params >> value;
				if (value > 1)
					ann_p.l = value;
				continue;
			}
			
			if (in_param == "annealing.alpha")
			{
				control_params >> value_double;
				if (value_double > 1)
					ann_p.alpha = value_double;
				continue;
			}
		}
	}

	void grasp_params(ifstream& control_params)
	{
		/*
			Objective:
				Parse and set the parameters for the GRASP algorithm from a file.

			Parameters:
				- control_params: Reference to the ifstream containing the parameter values.
		*/

		string in_param;
		int value;
		LD value_double;

		while (control_params >> in_param && in_param != "end")
		{
			if (in_param == "grasp.m")
			{
				control_params >> value;
				if (value > 1)
					grasp_p.m = value;
				continue;
			}

			if (in_param == "grasp.beta")
			{
				control_params >> value;
				if (value > 1)
					grasp_p.beta = value;
				continue;
			}
			
			if (in_param == "grasp.l")
			{
				control_params >> value_double;
				if (value_double > 1)
					grasp_p.l = value_double;
				continue;
			}
		}
		
		grasp_p.cont_alpha.assign(grasp_p.m, 0);
		grasp_p.p_alpha.assign(grasp_p.m, 1.0 / grasp_p.m);
		grasp_p.solution_alpha.assign(grasp_p.m, 0.0);
	}
};


struct point 
{
	/*
		Objective:
			A structure to represent a point in the Cartesian plane with coordinates X and Y.
	*/

	LD X, Y;
	point(LD x, LD y) : X(x), Y(y) {}
};

class utilities
{
    /*
        Objective:
            Utility class containing various useful functions for solving optimization problems.

		Attributes:
			param: Object of class params containing algorithm parameters.
			n_cities: Number of cities.
			city: Vector containing points representing cities in the Cartesian plane
			input_predicted: Input predicted.
	*/

public:
	static params param;
	static LD input_predicted;
	static int n_cities;
	static vector<point> city;
	
	static void random_path(const int& initial,const bool& reapeat, LD& fit, vector<int>& path, vector<bool>& contain)
	{
		/*
			Objective:
				Method that creates a random path.
			Parameters:
				- initial: Initial index for the path.
				- repeat: Flag indicating whether to allow repeated cities in the path.
				- fit: Reference to the fitness value of the generated path.
				- path: Reference to the generated path.
				- contain: Vector indicating which cities are included in the path.
		*/

		path[0] = initial;
		contain[initial] = 1;
		
		for (int i = 1; i < n_cities; i++)
		{
			int idx = utilities::random_range(0, n_cities);
			
			while (!reapeat && contain[idx])
			{
				idx = utilities::random_range(0, n_cities);
			}

			path[i] = idx;
			contain[idx] = 1;
		}
		fit = Fx_fit(path, n_cities, contain);
	}

	static void random_path(const int& initial,const bool& reapeat, LD& fit, vector<int>& path, vector<int>& repath, vector<bool>& contain)
	{
		/*
			Objective:
				Method that creates a random path.
			Parameters:
				- initial: Initial index for the path.
				- repeat: Flag indicating whether to allow repeated cities in the path.
				- fit: Reference to the fitness value of the generated path.
				- path: Reference to the generated path.
				- repath: Reference to the path represented by city indices.
				- contain: Vector indicating which cities are included in the path.
		*/

		path[0] = initial;
		repath[initial] = 0;
		contain[initial] = 1;
		
		for (int i = 1; i < n_cities; i++)
		{
			int idx = utilities::random_range(0, n_cities);
			
			while (!reapeat && contain[idx])
			{
				idx = utilities::random_range(0, n_cities);
			}

			path[i] = idx;
			repath[idx] = i;
			contain[idx] = 1;
		}
		fit = Fx_fit(path, n_cities, contain);
	}

	static LD euclidian_distance(const point& a, const point& b)
	{
		/*
			Objective:
				Calculate the Euclidean distance between two points.
			Parameters:
				- a: First point.
				- b: Second point.
			Returns:
				Euclidean distance between points a and b.
		*/

		return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
	}

	static LD Fx_fit(const vector<int>& path, const int& n, const vector<bool>& contain)
	{
		/*
			Objective:
				Calculate the fitness value of a path based on the total distance traveled and city inclusion.
			Parameters:
				- path: Path represented by a vector of city indices.
				- n: Number of cities.
				- contain: Vector indicating which cities are included in the path.
			Returns:
				Fitness value of the path.
		*/

		LD fit = 0;

		for (int i = 0; i < n - 1; i++)
		{
			fit += utilities::euclidian_distance(city[path[i]], city[path[i + 1]]);
		}

		fit += utilities::euclidian_distance(city[path[n-1]], city[path[0]]);

		for (int i = 0; i < n; i++)
		{
			if (!contain[i])
			{

				fit = INF - fit;
				return fit;
			}
		}

		return fit;
	}

	static LD Fx_fit(const vector<int>& path, const int& n)
	{
		/*
			Objective:
				Calculate the fitness value of a path based on the total distance traveled.
			Parameters:
				- path: Path represented by a vector of city indices.
				- n: Number of cities.
			Returns:
				Fitness value of the path.
		*/

		LD fit = 0;

		for (int i = 0; i < n - 1; i++)
		{
			fit += utilities::euclidian_distance(city[path[i]], city[path[i + 1]]);
		}

		fit += utilities::euclidian_distance(city[path[n-1]], city[path[0]]);

		return fit;
	}

	static int random_range(int start=0, int end=INT_MAX)
	{
		/*
			Objective:
				Find a random integer within a specified range.
			Parameters:
				- start: Start of the range (inclusive).
				- end: End of the range (exclusive).
			Returns:
				Random integer within the specified range.
		*/

		if(start > end) 
			swap(start, end);
		
		uniform_int_distribution<> dis(start, end-1);
		return dis(gen);
	}

	static LD random_range_double(int start=0, int end=1)
	{
		/*
			Objective:
				Find a random real number within a specified range.
			Parameters:
				- start: Start of the range.
				- end: End of the range.
			Returns:
				Random real number within the specified range.
		*/

		uniform_real_distribution<> dis(start, end);
		return dis(gen);
	}

	static void input_points(string source = INPUT_FILE)
	{
		/*
			Objective:
				Input points from a file.
			Parameters:
				- source: Path to the input file.
		*/

		ifstream input(source);
		int n;
		input >> n;
		n_cities = n;

		while (n--)
		{
			LD x, y;
			input >> x >> y;
			city.push_back(point(x, y));
		}

		LD predicted;
		input >> predicted;
		input_predicted = predicted;
	}


		static void opt_2(vector<int>& best_path, LD& best_fit, bool mutation = false, vector<bool> contain = {})
		{
			/*
				Objective:
					Implement the 2-opt heuristic for optimizing a path.

				Parameters:
					- best_path: Reference to the best path found.
					- best_fit: Reference to the fitness of the best path found.
					- mutation: Flag indicating whether to apply mutation.
					- contain: Optional vector indicating which cities should be included in the optimization.
			*/

		vector<int> save_path, path_copy;
		LD cust_copy = INF;

		path_copy = save_path = best_path;

		for (int i = 0; i < n_cities; i++)
		{
			for (int j = i + 1; j < n_cities; j++)
			{
				int idxA = i;
				int idxB = j;

				while (idxA < idxB)
				{
					swap(path_copy[idxA], path_copy[idxB]);
					idxA++;
					idxB--;
				}
				
				if (contain.empty())
					cust_copy = utilities::Fx_fit(path_copy, n_cities);
				else
					cust_copy = utilities::Fx_fit(path_copy, n_cities, contain);

				if (!mutation && cust_copy < best_fit)
					best_path = path_copy, best_fit = cust_copy;
				else
					if(mutation)
						best_path = path_copy, best_fit = cust_copy;

				path_copy = save_path;
			}
		}   
	}

	static void opt_2s(vector<int>& best_path, LD& best_fit, bool mutation = false, vector<bool> contain = {})
	{
		/*
			Objective:
				Implement the stochastic 2-opt heuristic for optimizing a path.

			Parameters:
				- best_path: Reference to the best path found.
				- best_fit: Reference to the fitness of the best path found.
				- mutation: Flag indicating whether to apply mutation.
				- contain: Optional vector indicating which cities should be included in the optimization.
		*/

		vector<int> path_copy = best_path;
		LD cust_copy = INF;
		int idxA = utilities::random_range(1, n_cities);
		int idxB = utilities::random_range(1, n_cities);

		while (idxB == idxA)
			idxB = utilities::random_range(1, n_cities);

		if (idxA > idxB)
			swap(idxA, idxB);

		while (idxA < idxB)
		{
			swap(path_copy[idxA], path_copy[idxB]);
			idxA++;
			idxB--;
		}
		
		if (contain.empty())
			cust_copy = utilities::Fx_fit(path_copy, n_cities);
		else
			cust_copy = utilities::Fx_fit(path_copy, n_cities, contain);

		if (!mutation && cust_copy < best_fit)
			best_path = path_copy, best_fit = cust_copy;
		else
			if(mutation)
				best_path = path_copy, best_fit = cust_copy;
	}

	static void opt1(vector<int>& best_path, LD& best_fit, bool mutation = false, vector<bool> contain = {})
	{
		vector<int> path_copy = best_path;
		LD cust_copy = INF;
		int idxA = utilities::random_range(1, n_cities);
		int idxB = utilities::random_range(1, n_cities);

		while(idxA == idxB)
			idxB = utilities::random_range(1, n_cities);

		swap(path_copy[idxA], path_copy[idxB]);

		if (contain.empty())
			cust_copy = utilities::Fx_fit(path_copy,n_cities);
		else
			cust_copy = utilities::Fx_fit(path_copy,n_cities, contain);

		if (!mutation && cust_copy < best_fit)
			best_path = path_copy, best_fit = cust_copy;
		else
			if(mutation)
				best_path = path_copy, best_fit = cust_copy;
	}

	static LD calculateR2(LD observed, LD predicted) 
	{
		/*
			Objective:
				Calculate the coefficient of determination (R^2).
			Parameters:
				- observed: Observed value.
				- predicted: Predicted value.
			Returns:
				Coefficient of determination (R^2).
		*/

		LD rSquared = 1.0 - pow(observed - predicted, 2) / pow(observed, 2);
		return rSquared;
	}

	static LD calculateMAE(LD observed, LD predicted) 
	{
		/*
			Objective:
				Calculate the mean absolute error (MAE).
			Parameters:
				- observed: Observed value.
				- predicted: Predicted value.
			Returns:
				Mean absolute error (MAE).
		*/

		LD mae = std::abs(observed - predicted);
		return mae;
	}

	static LD calculateMSE(LD observed, LD predicted) 
	{
		/*
			Objective:
				Calculate the mean squared error (MSE).
			Parameters:
				- observed: Observed value.
				- predicted: Predicted value.
			Returns:
				Mean squared error (MSE).
		*/

		LD mse = pow(observed - predicted, 2);
		return mse;
	}
};

struct hash_pair 
{ 
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const
	{
		/*
			Objective:
				Hash function for pair objects.
		*/
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);

		if (hash1 != hash2) {
			return hash1 ^ hash2;              
		}
		
		return hash1;
	}
};
