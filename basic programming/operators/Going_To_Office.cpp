#include <bits/stdc++.h>

using namespace std;

int64_t onlineTaxiCost(int64_t d, int64_t &oc, int64_t &of, int64_t &od)
{
    if (d <= of) {
        return oc;
    } else {
        int64_t firsts_km_cost = oc;
        d -= of;
        int64_t extra_cost = d * od;
        return firsts_km_cost + extra_cost;
    }
}

int64_t classicTaxiCost(int64_t d, int64_t &cs, int64_t &cb, int64_t &cm, int64_t &cd)
{
    int64_t total_cost = cb;
    total_cost += (d/cs) * cm;
    total_cost += d * cd;
    return total_cost;
}

int main()
{
    int64_t d, oc, of, od, cs, cb, cm, cd;
    cin >> d;
    cin >> oc >> of >> od;
    cin >> cs >> cb >> cm >> cd;

    int64_t onlineTaxi = onlineTaxiCost(d, oc, of, od);
    int64_t classicTaxi = classicTaxiCost(d, cs, cb, cm, cd);
    
    if (onlineTaxi <= classicTaxi) {
        cout << "Online Taxi\n";
    } else {
        cout << "Classic Taxi\n";
    }

    return 0;
}