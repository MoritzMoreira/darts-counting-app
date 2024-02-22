#include <iterator>
#include <algorithm>
#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include "darts.h"
#include <iomanip>
#include <sstream>

template<typename T>
std::string to_string_with_precision(const T a_value, const int n)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return std::move(out).str();
}

void counter::checkout_loop(int countdown_p){
     for (int j=3; j!=0; j-=2){
            for (int i = 20; i >-2; --i) {
                  std::map<std::string, double> ct_m = {}; std::string ct_s = "";
                  result test_result = checkout_test(countdown_p, ct_m, ct_s, i, j);
                  int cd_afterDart1 = test_result.countdown_i;
                  std::map<std::string, double> ct_afterD1_m = test_result.current_targets_p;
                  std::string ct_afterD1_s = test_result.ct_p;
                  if (cd_afterDart1 < 2 || checkout.size() > limit) {break;}

                  for (int k=3; k!=0; k -= 2){
                         for (int l = 20; l >-2; --l) {
                              result test_result2 = checkout_test(cd_afterDart1, ct_afterD1_m, ct_afterD1_s, l, k);
                              int cd_afterDart2 = test_result2.countdown_i;
                              std::map<std::string, double> ct_afterD2_m = test_result2.current_targets_p;
                              std::string ct_afterD2_s = test_result2.ct_p;
                              if (cd_afterDart2 < 2 || checkout.size() > limit) {break;}

                              for (int u=3; u!=0; u -= 2){
                                  for (int m = 20; m >-2; --m) {
                                       result test_result3 = checkout_test(cd_afterDart2, ct_afterD2_m, ct_afterD2_s, m, u);
                                       int cd_afterD3 = test_result3.countdown_i;
                                       std::map<std::string, double> ct_afterD3_m = test_result3.current_targets_p;
                                       std::string ct_afterD3_s = test_result3.ct_p;
                                       if (cd_afterD3 <=170 && std::find(std::begin(no_checkout), std::end(no_checkout), countdown) == std::end(no_checkout)){
                                            insertion_checkout(ct_afterD3_m, ct_afterD3_s);
                                       }
                                         if (cd_afterD3 < 2 || checkout.size() > limit) {break;}
                                  }
                                  if (u == 1) {
                                       u += 3;
                                  }
                               }
                          }
                          if (k == 1) {
                               k += 3;
                          }
                   }
             }
             if (j == 1) {
                 j += 3;
             }
     }
     for (unsigned int m = 0; m < checkout.size(); m++){
         checkout_v[m] += to_string_with_precision(diffSum(checkout[m]), 3);
     }
}

void counter::finish_loop(int countdown_p){
     for (int j=3; j!=0; j-=2){
            for (int i = 20; i >-2; --i) {
                  std::map<std::string, double> ct_m = {}; std::string ct_s = "";
                  result test_result = checkout_test(countdown_p, ct_m, ct_s, i, j);
                  int cd_afterDart1 = test_result.countdown_i;
                  std::map<std::string, double> ct_afterD1_m = test_result.current_targets_p;
                  std::string ct_afterD1_s = test_result.ct_p;
                  if (cd_afterDart1 == 0 && (ct_afterD1_s.at(ct_afterD1_s.length()-6) == 'B' || ct_afterD1_s.at(ct_afterD1_s.length()-4) == 'D' || ct_afterD1_s.at(ct_afterD1_s.length()-5) == 'D')){
                        insertion(ct_afterD1_m, ct_afterD1_s);
                        break;
                  }
                  else if (cd_afterDart1 < 2 || finish.size() > limit) {break;}

                  for (int k=3; k!=0; k-=2){
                         for (int l = 20; l >-2; --l) {
                              result test_result2 = checkout_test(cd_afterDart1, ct_afterD1_m, ct_afterD1_s, l, k);
                              int cd_afterDart2 = test_result2.countdown_i;
                              std::map<std::string, double> ct_afterD2_m = test_result2.current_targets_p;
                              std::string ct_afterD2_s = test_result2.ct_p;
                              if (cd_afterDart2 == 0 && (ct_afterD2_s.at(ct_afterD2_s.length()-6) == 'B' || ct_afterD2_s.at(ct_afterD2_s.length()-4) == 'D' || ct_afterD2_s.at(ct_afterD2_s.length()-5) == 'D')){
                                    insertion(ct_afterD2_m, ct_afterD2_s);
                                    break;
                              }
                              else if (cd_afterDart2 < 2 || finish.size() > limit) {break;}

                              for (int m = 20; m >-2; --m) {
                                   result test_result3 = checkout_test(cd_afterDart2, ct_afterD2_m, ct_afterD2_s, m, 2);
                                   int cd_afterD3 = test_result3.countdown_i;
                                   std::map<std::string, double> ct_afterD3_m = test_result3.current_targets_p;
                                   std::string ct_afterD3_s = test_result3.ct_p;
                                   if (cd_afterD3 == 0 && (ct_afterD3_s.at(ct_afterD3_s.length()-6) == 'B' || ct_afterD3_s.at(ct_afterD3_s.length()-4) == 'D' || ct_afterD3_s.at(ct_afterD3_s.length()-5) == 'D')){
                                       insertion(ct_afterD3_m, ct_afterD3_s);
                                       break;
                                   }
                                   else if (cd_afterD3 < 2 || finish.size() > limit) {break;}
                               }
                           }
                           if (k == 1) {
                                k += 3;
                           }
                    }
                }
                if (j == 1) {
                      j += 3;
                }
     }
     for (unsigned int m = 0; m < finish.size(); m++){
         finish_v[m] += to_string_with_precision(diffSum(finish[m]), 3);
     }
}
