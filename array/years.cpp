#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> birth(n);
    vector<int> death(n);
    for(int i=0; i<n; ++i)
        cin>>birth[i]>>death[i];
    // pop - population 
    // it will change only on birth and death of someone and so we keep updating it and take max of it 
    int population = 0;
    sort(birth.begin(), birth.end());
    sort(death.begin(), death.end());
    int i = 0;
    int j = 0;
    int max_pop = 0, max_pop_year;
    while(i!=n){
        if(death[j]<=birth[i]){
            population--;
            j++;
        }
        else{
            population++;
            if(population>max_pop){
                max_pop = population;
                max_pop_year = birth[i];
            }
            i++;
        }
    }
    cout<<max_pop_year<<" "<<max_pop<<endl;
    return 0;
}
