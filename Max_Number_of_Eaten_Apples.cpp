// Leetcode 1705 

typedef pair<int,int> pii;
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        //Make a priority queue --> pq (pair - {rotten day , no of apples} ) and sort according to increasing rotten day
        priority_queue<pii, vector<pii>, greater<pii> >pq;
        int n = apples.size();
        int eatenApples = 0;
        //Process apples which are not processed or until we still have good apples in the queue
        for(int i = 0; i<n || !pq.empty(); i++)
        {
            //Push condition in the queue
            if(i < n && apples[i])
              pq.push(make_pair(i+days[i],apples[i]));
              
            //Remove already rotten apples which are still present in the queue
            while(!pq.empty() && i >= pq.top().first)
              pq.pop();
           
           //If we have good apples then we have to eat it to keep the dr away
             if(!pq.empty())
             {
                     auto p = pq.top(); 
                     pq.pop();
                     
                    // Not reached the nth day yet (Note : we are trying to eat atmost 1 apple a day here)
                    if(i < n )  
                    {
                        eatenApples ++ ;   //eat the good apple
                        p.second--;        //one apple consumed 
                        // If still good apples remains push it in our good apple queue
                        if(p.second > 0)
                        pq.push(p);
                    }
                    else
                    {
                         // Note - we are eating in the greedy fashion so as to consume max no of apples, i.e first eating those
                         // apples which get rotten earlier
                         // Add minimum of days left or no of good apples left for the current pair
                         int add = min(p.first - i, p.second);
                         eatenApples += add;
                         // set the day upto which we have already eaten so as to check for the comming days
                         i += add - 1;
                         
                    }
             }
           
        }
       
        return eatenApples;
    }
};
