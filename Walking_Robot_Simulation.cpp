//Leetcode 874

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		unordered_map<int, vector<int>> obs_x; //obs_x[i]表示X=i直线上是障碍物的y坐标系列
		unordered_map<int, vector<int>> obs_y; //obs_y[i]表示Y=i直线上是障碍物的x坐标系列
		for(int i=0;i<obstacles.size();++i) {
			int x = obstacles[i][0], y = obstacles[i][1];
			obs_x[x].push_back(y);
			obs_y[y].push_back(x);
		}
		for(auto ind = obs_x.begin(); ind != obs_x.end(); ++ind) {
			sort(ind->second.begin(), ind->second.end());
		}
		for(auto ind = obs_y.begin(); ind != obs_y.end(); ++ind) {
			sort(ind->second.begin(), ind->second.end());
		}
		int cur_x = 0, cur_y = 0;
		int ori = 1; //1向上，2向下，3向左，4向右
		//commands：-2，向左90度，-1向右90度
    int res = 0;
		for(int i=0;i<commands.size();++i) {
			int c=commands[i];
			if(c==-2) {
				if(ori == 1) ori = 3;
				else if(ori == 2) ori = 4;
				else if(ori == 3) ori = 2;
				else ori = 1;
				continue;
			}
			else if(c==-1) {
				if(ori == 1) ori = 4;
				else if(ori == 2) ori = 3;
				else if(ori == 3) ori = 1;
				else ori = 2;
				continue;
			}
			if(ori == 1) {
				int new_y = cur_y + c; //从(cur_x, cur_y)到达(cur_x, new_y)
				vector<int> obs = obs_x[cur_x];
				if(obs.size() > 0) {
					auto ind = lower_bound(obs.begin(), obs.end(), cur_y); //找到第一个>=cur_y的障碍物
					if(ind != obs.end() && (*ind) <= new_y && (*ind) > cur_y) new_y = (*ind) - 1;
				}
				cur_y = new_y;
			}
			else if(ori == 2) {
				int new_y = cur_y - c; //从(cur_x, cur_y)到达(cur_x, new_y)
				vector<int> obs = obs_x[cur_x];
				if(obs.size() > 0) {
					auto ind = upper_bound(obs.begin(), obs.end(), cur_y); //找到第一个>cur_y的障碍物
					if(ind != obs.begin() && (*(ind-1)) >= new_y && (*(ind-1)) != cur_y) new_y = (*(ind-1)) + 1;
				}
				cur_y = new_y;
			}
			else if(ori == 3) {
				int new_x = cur_x - c;
				vector<int> obs = obs_y[cur_y];
				if(obs.size() > 0) {
					auto ind = upper_bound(obs.begin(), obs.end(), cur_x);
					if(ind != obs.begin() && (*(ind-1)) >= new_x && (*(ind-1)) != cur_x) new_x = (*(ind-1)) + 1;
				}
				cur_x = new_x;
			}
			else {
				int new_x = cur_x + c;
				vector<int> obs = obs_y[cur_y];
				if(obs.size() > 0) {
					auto ind = lower_bound(obs.begin(), obs.end(), cur_x);
					if(ind != obs.end() && (*ind) <= new_x && (*ind) != cur_x) new_x = (*ind) - 1;
				}
				cur_x = new_x;
			}
      int dist = cur_x * cur_x + cur_y * cur_y;
      res = max(res, dist);
		}
    return res;
    }
};
