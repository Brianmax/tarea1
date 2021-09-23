#include <bits/stdc++.h>
using namespace std;
#define M 25
#define N 20000
int pick = 0;
vector<vector<int>> points;
int ratio_d[11]={};
double min_d = INT_MAX;
double max_d = 0;
void get_radom()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);
    for(int i = 0; i < N; i++)
    {
        vector<int> tmp;
        for(int j = 0; j < M; j++)
            tmp.push_back(dis(gen));
        points.push_back(tmp);
    }
}
double distanceBetween2Points(vector<int> pointA, vector<int> pointB)
{
    double answer = 0;
    double tmp = 0;
    for(int i = 0; i < M; i++)
        tmp = tmp + pow((pointA[i] - pointB[i]),2);
    answer = sqrt(tmp);
    return answer;
}
vector<double> distance()
{
    double d = 0;
    vector<double> ds;
    for(int i = 0; i < N; i++)
    {
        if(pick == i)
            continue;
        d = distanceBetween2Points(points[pick], points[i]);
        if(min_d > d)
            min_d = d;
        if(max_d < d)
            max_d = d;
        ds.push_back(d);
    }
    return ds;
}
int get_random_number()
{
    srand(time(0));
    return (rand() % N-2);
}
void getRatio(vector<double> dis)
{
    float tmp = (max_d-min_d);
    int size = dis.size();
    for(int i = 0; i < size; i++)
    {
        double t = dis[i]-min_d;
        t = t/tmp; //0.3638
        t = t*10; //3.638
        int r = t;
        //cout<<"fa: "<<r<<endl;
        ratio_d[r]++;
    }
}
int main()
{
    get_radom();
    pick = get_random_number();
    vector<double> dis;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
    dis = distance();
    //cout<<min_d<<"   "<<max_d<<endl;
    getRatio(dis);
    end = std::chrono::high_resolution_clock::now();
    int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); // duration is holding the elapsed time
    cout<<"tiempo: "<<duration<<endl;
    for(auto x: ratio_d)
        cout<<x<<endl;
    return 0;
}