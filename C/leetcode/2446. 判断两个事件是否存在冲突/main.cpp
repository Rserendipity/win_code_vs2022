  class Solution {
  public:
	  bool haveConflict(vector<string>& c1, vector<string>& c2) {
		  vector<int> mu;
		  for (int i = 0; i < 2; i++)
		  {
			  int ls = (c1[i][0] - '0') * 10 * 60 + (c1[i][1] - '0') * 60 + (c1[i][3] - '0') * 10 + c1[i][4] - '0';
			  mu.push_back(ls);
		  }
		  for (int i = 0; i < 2; i++)
		  {
			  int ls = (c2[i][0] - '0') * 10 * 60 + (c2[i][1] - '0') * 60 + (c2[i][3] - '0') * 10 + c2[i][4] - '0';
			  mu.push_back(ls);
		  }
		  if (mu[2] > mu[1] || mu[0] > mu[3])
		  {
			  return false;
		  }
		  return true;
	  }
  };