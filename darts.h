#include <vector>
#include <iostream>
#include <map>

#ifndef DARTS_H_INCLUDED
#define DARTS_H_INCLUDED

class counter{
public:
    struct result{
        int countdown_i;
        std::map<std::string, double> current_targets_p;
        std::vector<std::pair<int,int>> ct_p;
    };
    void checkout_loop(int);
    void finish_loop(int);
    void print(std::vector<std::vector<std::pair<int,int>>>);

    int countdown = 501, score = 20;
    std::vector<std::vector<std::pair<int,int>>> finish_v, checkout_v;
    std::vector<std::vector<std::pair<int,int>>> finish_v_ordered;
    int no_checkout[7] = {169, 168, 166, 165, 163, 162, 159};

private:
    result checkout_test(int, std::map<std::string, double>, std::vector<std::pair<int,int>>, int, int);
    // insertion rules:
    double diffSum(std::vector<std::pair<int,int>>);
    int scoreSum(std::vector<std::pair<int,int>>);
    int scoreSumSingle(std::vector<std::pair<int,int>>);
    int scoreSumSingle_finish(std::vector<std::pair<int,int>>);
    int double_bull_count(std::vector<std::pair<int,int>> ct_p);
    int bull_count(std::vector<std::pair<int,int>> ct_p);
    bool maxSingle(std::vector<std::pair<int,int>> finish_v_p, std::vector<std::pair<int,int>> ct_p);
    void insertion(std::map<std::string, double>, std::vector<std::pair<int,int>>);
    void insertion_checkout(std::map<std::string, double>, std::vector<std::pair<int,int>>);

    double diff[5] = {2322.576, 419.354, 258.064, 129.032, 677.418};
    std::string bed_names[5] = {"", "D", "T", "Bull", "DBull"};
    unsigned int limit = 1000, print_limit = 5;
};


#endif // DARTS_H_INCLUDED
