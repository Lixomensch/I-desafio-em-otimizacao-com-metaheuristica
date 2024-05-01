#pragma once
#include "library.hpp"
#include "genetic.hpp"
#include "annealing.hpp"
#include "grasp.hpp"

class TSP
{

public:
	void run()
	{
		genetic ga(utilities::n_cities);
		LD best = INF;
		vector<int> path;

		for(int i = 0;i<utilities::n_cities;i++){
			path.push_back(i);
		}
		best=utilities::Fx_fit(path,utilities::n_cities);
		
		if (utilities::param.hybrid[0])
		{
			ga.activate();
			best = ga.best_fit();
			path = ga.best_path();
		}

		if (utilities::param.hybrid[1])
		{
			annealing ann(path, best);
			LD best_ann = ann.solution();

			if (best_ann < best)
			{
				best = best_ann;
				path = ann.best_solution;
			}
		}

		if (utilities::param.hybrid[2])
		{
			grasp gra(path, best);
			LD best_gra = gra.solution();

			if (best_gra < best)
			{
				best = best_gra;
				path = gra.best_solution;
			}
		}

		cout<< endl << best << endl;
	}
};
