class Solution {
public:
    struct node
    {
        node(int _x,int _y):x(_x),y(_y){}
        int x,y;
    };
    vector<double> sampleStats(vector<int>& count) {
        int minimum=-1, maximum,median, mode,mc=0;
        int sumc=0;
        double sum_all=0,mean;
        for(int i=0;i<count.size();i++)
            if(count[i])
            {   
                minimum=minimum==-1?i:minimum;
                maximum=i;
                if(count[i]>mc)
                    mode=i,mc=count[i];
                sumc+=count[i];
                sum_all=sum_all+1.0*i*count[i];
            }
        mean=sum_all/sumc;
        int mi,to=0,l,r;

        if(sumc%2==0)
        {
            median=sumc/2;
            mi=sumc/2+1;
        }
        else{
             median=sumc/2+1;
            mi=sumc/2+1;
        }
        cout<<sumc<<" "<<median<<" "<<mi<<endl;
        for(int i=0;i<count.size();i++)
            if(count[i])
            {   
                if(to<median&&to+count[i]>=median)
                    l=i;
                if(to<mi&&to+count[i]>=mi)
                    r=i;
                to+=count[i];
            }
        vector<double>res;
        res.push_back(minimum);
        res.push_back(maximum);
        res.push_back(mean);
        res.push_back(1.0*(l+r)/2);
        res.push_back(mode);
        return res;
    }
};