// Using math functions

#include <iostream>
#include <cmath>
using namespace std;

int main() {
   double x;
   double y;
   double z;

   cin >> x >> y >> z;
   
   double xz = pow(x, z);
   
   double x_yz = pow(x, pow(y,z));
   
   double abs_y = fabs(y);
   
   double xy_z = sqrt(pow(x * y, z));
   
   cout << xz << " " << x_yz << " " << abs_y << " " << xy_z << endl;

   
   return 0;
}
