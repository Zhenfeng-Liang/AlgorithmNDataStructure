// Write a method that returns all subsets of a set.
// This was implemented in Java

/*
ArrayList<ArrayList<Integer>> getSubsets(ArrayList<Integer> set, int index)
{
	
    ArrayList<ArrayList<Integer>> allsubsets;
	
    if (set.size() == index) {
		
        allsubsets = new ArrayList<ArrayList<Integer>>();
		
        allsubsets.add(new ArrayList<Integer>()); // Empty set
	
    } else {
		
        allsubsets = getSubsets(set, index + 1);
		
        int item = set.get(index);
		
        ArrayList<ArrayList<Integer>> moresubsets =
			
            new ArrayList<ArrayList<Integer>>();
		
        for (ArrayList<Integer> subset : allsubsets) {
			
            ArrayList<Integer> newsubset = new ArrayList<Integer>();
			
            newsubset.addAll(subset); 
			
            newsubset.add(item);
			
            moresubsets.add(newsubset);
		
        }
		
        allsubsets.addAll(moresubsets);
	
    }
	
    return allsubsets;
}
*/



// C++, given a vector of int, return all the subset of the vector
//
// Zhenfeng Liang
//
// All copyrights reserved

#include <vector>
#include <iostream>

using namespace std;

vector< vector<int> > getSubsets(const vector<int>& set, int index)
{

    vector< vector<int> > allsubsets;        

    if(set.size() == index)
    {
        vector<int> tmp; // empty set
        allsubsets.push_back(tmp);
    }
    else
    {
        allsubsets = getSubsets(set, index + 1);

        int n = allsubsets.size();
        int item = set[index];
        
        vector< vector<int> > moresubsets;
        for(int i = 0; i < n; i++)
        {
            vector<int> tmp = allsubsets[i];
            tmp.push_back(item);
            moresubsets.push_back(tmp);
        }

        allsubsets.insert(allsubsets.end(), moresubsets.begin(), moresubsets.end());        
    }

    return allsubsets;
}

void printSubsets(vector< vector<int> > allsubsets)
{
    int nrow = allsubsets.size();

    for(int i = 0; i < nrow; i++)
    {
        int ncol = allsubsets[i].size();

        for(int j = 0; j < ncol; j++)
        {
            cout << allsubsets[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char ** argv)
{

    int tmp [] = {
        1,2,3,4,5
    };

    vector<int> set(tmp, tmp + sizeof(tmp) / sizeof(int));
 
    vector< vector<int> > allsubsets;
    allsubsets = getSubsets(set, 0);

    printSubsets(allsubsets);

    cout << "number of subsets: " << allsubsets.size() << endl;
    
    return 0;    
}
