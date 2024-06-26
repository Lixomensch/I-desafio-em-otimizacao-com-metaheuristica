#pragma once
#include "library.hpp"

struct bee {
    vector<int> path;
    double cost;
    int cycle;
    char role;

    bee(vector<int> initial_path, double initial_cost) 
    {
        /*
            Objective:
                Constructor for the bee struct.
            Parameters:
                - initial_path: Initial path of the bee.
                - initial_cost: Initial cost of the path.
        */
        path = initial_path;
        cost = initial_cost;
    }
};

class ABC {
    int n_cities;
    int cycles_limit;
    int employed_limit;
    int colony_size;
    double scout_percent;
    double onlooker_percent;
    double employed_percent;

public:
    vector<int> best_solution;
    LD best_cost;

    ABC(vector<int> initial_solution, LD initial_cost) 
    {
        /*
            Objective:
                Constructor for the ABC class.
            Parameters:
                - initial_solution: Initial solution of the ABC algorithm.
                - initial_cost: Initial cost of the solution.
        */

        n_cities = utilities::n_cities;
        cycles_limit = utilities::param.abc_p.cycles_limit;
        employed_limit = utilities::param.abc_p.employed_limit;
        colony_size = utilities::param.abc_p.colony_size;
        scout_percent = utilities::param.abc_p.scout_percent;
        onlooker_percent = utilities::param.abc_p.onlooker_percent;
        employed_percent = utilities::param.abc_p.employed_percent;
        best_solution = initial_solution;
        best_cost = initial_cost;
    }

    void initialize_hive(vector<bee> &hive) 
    {
        /*
            Objective:
                Initializes the hive with bees.
            Parameters:
                - hive: Reference to the vector representing the hive.
        */

        for (int i = 0; i < colony_size; ++i) 
        {
            bee bee(best_solution, best_cost);
            hive.push_back(bee);
        }
    }

    void clt(vector<bee> &hive) 
    {
        /*
            Objective:
                Assigns roles (Onlooker or Forager) to the bees in the hive.
            Parameters:
                - hive: Reference to the vector representing the hive.
        */

        int onlooker_count = colony_size * onlooker_percent;

        for (int i = 0; i < onlooker_count; ++i) 
        {
            hive[i].role = 'O';
        }

        for (int i = onlooker_count; i < colony_size; ++i) 
        {
            random_shuffle(hive[i].path.begin(),hive[i].path.end());
            hive[i].role = 'E';
        }
    }

    vector<int> update_path(const vector<int> path)
    {
        vector<int> new_path = path;
        int random_idx = utilities::random_range(0, path.size() - 1);
        swap(new_path[random_idx], new_path[random_idx + 1]);
        
        return new_path;
    }

    void employed(bee &bee) 
    {
        /*
            Objective:
                Implements the employed bee phase.
            Parameters:
                - bee: Reference to the bee.
        */

        vector<int> new_path = update_path(bee.path);
        double new_cost = utilities::Fx_fit(new_path, n_cities);

        if (new_cost < bee.cost) 
        {
            bee.path = new_path;
            bee.cost = new_cost;
            bee.cycle = 0; // reset cycle so bee can continue to make progress
        } 
        else 
        {
            bee.cycle++;
        }

        if (bee.cycle >= employed_limit) 
        {
            bee.role = 'S';
        }
    }

    void scouter_bee(bee &bee_s) 
    {
        /*
            Objective:
                Implements the scout bee phase.
            Parameters:
                - bee_s: Reference to the scout bee.
        */

        random_shuffle(bee_s.path.begin(), bee_s.path.end());
        bee_s.cost = utilities::Fx_fit(bee_s.path, n_cities);
        bee_s.role = 'E';
        bee_s.cycle = 0;
    }

    void outlooker_bee(vector<bee> &hive) 
    {
        /*
            Objective:
                Implements the onlooker bee phase.
            Parameters:
                - hive: Reference to the vector representing the hive.
        */

        for (auto &bee : hive) 
        {
            if (bee.role == 'O') 
            {
                vector<int> new_path = update_path(best_solution);

                double new_cost = utilities::Fx_fit(new_path, n_cities);

                if (new_cost < best_cost)
                {
                    best_cost = new_cost;
                    best_solution = new_path;
                }
            }
        }
    }

    void bees_for_pollen(vector<bee> &hive, int scout_count)
     {
        /*
            Objective:
                Sends bees for pollen collection and updates their roles.
            Parameters:
                - hive: Reference to the vector representing the hive.
                - scout_count: Number of scout bees.
        */

        vector<pair<int, LD>> results;
        int m = hive.size();

        for (int i = 0; i < m; ++i)
        {
            if (hive[i].role == 'E')
            {
                employed(hive[i]);

                if (hive[i].cost < best_cost) 
                {
                    best_cost = hive[i].cost;
                    best_solution = hive[i].path;
                }
                results.push_back({i, hive[i].cost});
            }
            else if (hive[i].role == 'S')
            {
                scouter_bee(hive[i]);
            }
        }

        sort(results.begin(), results.end(), [](const auto &lb, const auto &rb)
             { return lb.second > rb.second; });

        m = results.size();

        for (int j = 0; j < scout_count && j < m; ++j) 
        {
            hive[results[j].first].role = 'S';
        }
    }

    LD solution() 
    {
        /*
            Objective:
                Executes the ABC algorithm to find the best solution.
            Returns:
                Best cost found by the algorithm.
        */
        vector<bee> hive;
        int scout_count = colony_size * scout_percent;
        initialize_hive(hive);
        clt(hive);

        for (int i = 0; i < cycles_limit; i++)
        {
            bees_for_pollen(hive, scout_count);
            outlooker_bee(hive);

        }

        return best_cost;
    }
};