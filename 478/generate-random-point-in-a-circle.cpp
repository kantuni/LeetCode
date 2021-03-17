class Solution {
  private:
    double R, Ox, Oy;
  
    double random() {
      static uniform_real_distribution<double> distribution(0, 1);
      static default_random_engine generator;
      return distribution(generator);
    }

  public:
    Solution(double radius, double x_center, double y_center) {
      this->R = radius;
      this->Ox = x_center;
      this->Oy = y_center;
    }
    
    vector<double> randPoint() {
      double theta = random() * 2 * M_PI;
      double d = sqrt(random()) * R;
      double x = Ox + d * cos(theta);
      double y = Oy + d * sin(theta);
      return {x, y};
    }
};
