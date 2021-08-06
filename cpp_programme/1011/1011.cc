#include <iostream>

#include <utility>
#include <vector>
#include <algorithm>
#include <math.h>

namespace{
using std::vector;
using std::pair;
using std::cout;
using std::cin;
using std::endl;
using std::min;
using std::max;
using std::sort;

double invalid = 9999999;

class Nearest_Point_Pair{
 public:
	Nearest_Point_Pair(){}

	~Nearest_Point_Pair(){}

	void initial_graph(){
		Set_Point_Pairs();
		Sort_Point_Pair_x(point_pair_);
		shortest_distance_ = Find_Shortest(point_pair_[0].first, point_pair_[point_pair_.size()-1].first);
	}

	int Find_Point_x(const double edge, int left, int right, vector<pair<int,int>>& pairs ){
    if(left>right)
        return -1;
    int mid =(left+right)/2;
		if(mid-1 < 0)
			return -1;
    if(pairs[mid-1].first > edge && pairs[mid].first <= edge)
        return mid;
    if(edge<pairs[mid].first)
        return Find_Point_x(edge, mid+1, right, pairs); 
    else
        return Find_Point_x(edge, left, mid-1, pairs); 
	}
	
	int Find_Point_y(const double edge, int left, int right, vector<pair<int,int>>& pairs ){
    if(left>right)
        return -1;
    int mid =(left+right)/2;
		if(mid-1 < 0)
			return -1;
    if(pairs[mid-1].second > edge && pairs[mid].second <= edge)
        return mid;
    if(edge<pairs[mid].second)
        return Find_Point_y(edge, mid+1, right, pairs); 
    else
        return Find_Point_y(edge,left, mid-1, pairs); 
	}

	double Find_Right_Shortest(pair<int,int>& point, vector<pair<int,int>>& pairs, double edge){
		double up_edge = point.second + edge;
		double down_edge = point.second - edge;
		int start = Find_Point_y(up_edge, 0 , (int)pairs.size(), pairs);
		if(start == -1)
			start = 0;
		int end = Find_Point_y(down_edge, 0 , (int)pairs.size(), pairs);
		if(end == -1)
			end = pairs.size();
		double min = pow(pairs[start].first - point.first, 2) + pow(pairs[start].second - point.second, 2);
		for(int i = start; i<= end; ++i){
			double temp = pow(pairs[i].first - point.first, 2) + pow(pairs[i].second - point.second, 2);
			if(temp < min)
				min = temp;
		}
		return sqrt(min);
	}

	static bool compare_x(pair<int,int> x, pair<int,int> y){
		return	(x.first > y.first);
	}

  void	Sort_Point_Pair_x(vector<pair<int,int>>& pairs){
		std::sort(pairs.begin(),pairs.end(),compare_x);
	}

	static bool compare_y(pair<int,int> x, pair<int,int> y){
		return	(x.second > y.second);
	}

  void	Sort_Point_Pair_y(vector<pair<int,int>>& pairs){
		std::sort(pairs.begin(),pairs.end(),compare_y);
	}

	void Set_Point_Pairs(){
		int num;
		cin>>num;
		for(int i = 0; i < num; i++){
			pair<int,int> temp;
			int x,y;
			cin>>x>>y;
			temp.first = x;
			temp.second = y;
			point_pair_.push_back(temp);
		}
	}

	double Find_Shortest(int left_edge, int right_edge){
		double possible_min_distance = right_edge - left_edge;
		double middle = possible_min_distance/2;
		if(right_edge > left_edge){
			double left_shortest = Find_Shortest(left_edge,middle);
			double right_shortest = Find_Shortest(middle, right_edge);
			double min_distance = min(left_shortest,right_shortest);
			vector<pair<int,int>> y_l_pairs = Sort_part_Point_Pairs(middle-min_distance/2,middle);
			vector<pair<int,int>> y_r_pairs = Sort_part_Point_Pairs(middle+1,middle+min_distance/2);
			for(size_t i = 0; i < y_l_pairs.size(); ++i){
				double temp = Find_Right_Shortest(y_l_pairs[i], y_r_pairs, min_distance);
				if(temp < possible_min_distance)
					possible_min_distance = temp;
				if(y_l_pairs.size() == 0)
					possible_min_distance = invalid;
			}
			min_distance = min(possible_min_distance, min_distance);
			return min_distance;
		}
		else
			return invalid; 
	}

	vector<pair<int,int>> Sort_part_Point_Pairs(double left, double right){
		int start = Find_Point_x(left, 0 , (int)point_pair_.size(), point_pair_);
		if(start == -1)
			start = 0;
		int end = Find_Point_x(right, 0 , (int)point_pair_.size(), point_pair_);
		if(end == -1)
			end = point_pair_.size();
		vector<pair<int,int>> part_pair;
		for(int i = start+1; i <= end; ++i){
			part_pair.push_back(point_pair_[i]);
		}
		Sort_Point_Pair_y(part_pair);
		return part_pair;
	}
		
	void print_min(){
		cout<<shortest_distance_<<endl;
	}

 private:
 vector<pair<int,int>> point_pair_;
 double shortest_distance_;
};
}

int main()
{
	int num;
	cin>>num;
  Nearest_Point_Pair* graphs = new Nearest_Point_Pair[num];
	for(int i = 0; i < num; ++i){
		graphs[i].initial_graph();
	}
	for(int i = 0; i < num; ++i){
		graphs[i].print_min();
	}
	delete[] graphs;
}
		
