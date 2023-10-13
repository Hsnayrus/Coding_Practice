#include <algorithm>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>
/*
Given a set of N jobs where each jobi has a deadline and profit associated with
it. Each job takes 1 unit of time to complete and only one job can be scheduled
at a time. We earn the profit associated with job if and only if the job is
completed by its deadline. Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with

that Job.
Example 1:
Input: N = 4 Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output: 2 60
Explanation: Job1 and Job3 can be done with maximum profit of 60
(20+40).
Example 2:
Input: N = 5 Jobs = {(1,2,100),(2,1,19),(3,2,27),
(4,1,25),(5,1,15)}
Output: 2 127
Explanation: 2 jobs can be done with maximum
profit of 127 (100+27).

Your Task :
You don't need to read input or print
anything. Your task is to complete the function JobScheduling() which takes an
integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns
the count of jobs and maximum profit as a list or vector of 2 elements. Expected

Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)
Constraints:
1 <= N <=105
1 <= Deadline <= N
1 <= Profit <= 500

 */
struct Job {
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline

    Job(int init_id, int init_dead, int init_profit) {
        id = init_id;
        dead = init_dead;
        profit = init_profit;
    }
};

bool comparator(Job first, Job second) {
    if (first.profit == second.profit) {
        return first.id > second.id;
    }
    return first.profit > second.profit;
}

class Solution {
  private:
    int findHighestDeadline(std::vector<Job> & jobs) {
        int highest = INT_MIN;
        for (size_t i = 0; i < jobs.size(); i++) {
            if (jobs[i].dead > highest) {
                highest = jobs[i].dead;
            }
        }
        // Will always return something other than INT_MIN
        // if jobs is not empty
        return highest;
    }

    bool insertIntoScheduledJobs(Job job, std::vector<int> & scheduledJobs) {
        int insertIndex = INT_MIN;
        for (int i = job.dead - 1; i >= 0; i--) {
            if (scheduledJobs[i] == -1) {
                insertIndex = i;
                break;
            }
        }
        if (insertIndex == INT_MIN) {
            return false;
        }
        scheduledJobs[insertIndex] = job.profit;
        return true;
    }
    void printArray(std::vector<int> array) {
        for (size_t i = 0; i < array.size(); i++) {
            std::cout << array[i];
            if (i != array.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

  public:
    // Function to find the maximum profit and the number of jobs done.
    std::vector<int> JobScheduling(Job arr[], int n) {
        std::vector<Job> jobs;
        // insert into jobs
        for (int i = 0; i < n; i++) {
            jobs.push_back(arr[i]);
        }
        std::vector<int> result(2, 0);
        std::sort(jobs.begin(), jobs.end(), comparator);
        int highest = findHighestDeadline(jobs);
        std::vector<int> scheduledJobs(highest, -1);
        for (size_t i = 0; i < jobs.size(); i++) {
            bool insert = insertIntoScheduledJobs(jobs[i], scheduledJobs);
            if (insert) {
                result[0]++;
                result[1] += jobs[i].profit;
            }
        }
        return result;
    }
};

int main() {
    Solution s1;
    Job arr[] = {Job(1, 4, 20), Job(2, 1, 10), Job(3, 1, 40), Job(4, 1, 30)};
    int n = 4;
    std::vector<int> result = s1.JobScheduling(arr, n);
    std::cout << result[0] << ", " << result[1] << std::endl;
    return 0;
}
