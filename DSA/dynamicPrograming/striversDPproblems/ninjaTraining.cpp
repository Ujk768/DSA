#include<iostream>
#include<vector>
using namespace std;
/**
 * @brief
 
 * ninja can train for 3 tasks and earn points for each task
 * performed. He cant perform same task on consecutive days
 * find max points the ninja can earn
 *
 *   1st 2nd 3rd  activity
 *  10 50  1   =>day 0
 *  5   100 11  => day 1
 *
 * use greedy approach
 *
 * day0=> 50  day 1=> 11  total=61 cant perform 100 as that same task was
 already performed earlier
 *
 * day0=> 10 day1=>100  total=110
 *
 * greedy approach fails
 *
 * whenever greedy fails we try all possible ways
 *
 * hence we use recursion
 *
 * steps:
 *  1.  express every problem in terms of index;
 *  2. Do stuff on that index
 *  3. find max
 *
 *  day can be an index
 *
 * // to write the recurrence relation we need to know what task we
 * had performed on the previous day
 *
 * we need to know what task was performed on the previous index
 *
 *
 * 0=> task1 was done
 * 1=> task2 was done
 * 2=> task3 was done
 * 3=> no task was done
 *
 * initially call will be made for f(n-1,3)=>give max points that
 * you can earn in an array that starts at 0 and ends at n-1 and
 * before n-1 no task were performed.
 *
 *
 * f(2,1) => max number of points that can be obtained from 0 to the 2nd index
 * given that task 1 was performed at the 3rd index
 *
 *
 *  f(day,last){
 *  // on the last day we just perform the maximum of the available tasks to do
 *      if(ind==0){
 *          maxi=0;
 *          for(i=0->2){
 *              if(i!=last) maxi=max(maxi,task[0][ind]);
 *          }
 *          return maxi;
 *      }
 *      maxi=0;
 *      for(i=0->2){
 *          if(i!=last){
 *
 *              points=task[day][i]+f(day-1,i)
 *              maxi=max(maxi,points);
 *
 *          }
 *      }
 *      return maxi;
 *
 *  }
 *
 *
 *
 *
 * day=>n
 *
 * last=> 4  tasks:0 1 2 3
 *
 * dp[n][4]={-1}
 *
 *
 */

int ninjaTrainingRecursive(int day,int last,vector<vector<int>>&points){
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }

    int maxi=0;

    for(int task=0;task<3;task++){
        if(task!=last){
            int point=points[day][task]+ninjaTrainingRecursive(day-1,task,points);
            maxi=max(maxi,point);
        }
    }
    return maxi;
}

//memoization

int ninjaTrainingRecursive(int day,int last,vector<vector<int>>&points, vector<vector<int>>&dp){
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi=0;

    for(int task=0;task<3;task++){
        if(task!=last){
            int point=points[day][task]+ninjaTrainingRecursive(day-1,task,points);
            maxi=max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
}

//t.c: O(n*4)*3  s.c: O(n*4)+O(n)



//tabulation => bottom up approach
int ninjaTrainingTabulation(vector<vector<int>>&points){
    int n=points.size();
    //dp array of size n * n+1
    vector<vector<int>>dp(n,vector<int>(4,0));
    // dp[day][lasttask]
    //for day 0 perform the max task except the last task performed
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][1],points[0][0]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=points[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
           
        }
    }
    return dp[n-1][3];
}

//t.c: O(n*4*3)  s.c: O(n*4)

//space optimizaton
int ninjaTrainingTabulationSpaceOptimized(vector<vector<int>>&points){
    int n=points.size();
    vector<int>prev(4,0);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][1],points[0][0]);

    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            int maxi=0;
            for(int task=0;task<3;task++){
                if(task!=last){

                    temp[last]=max(temp[last],points[day][task]+prev[task]);
                }
            }
            prev=temp;
        }
    }
    return prev[3];
}

//t.c: O(n*4*3)  s.c: O(4)
