#include "Plotter.h"1
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    PenStyle pen = {1, "black"};
    double penx;
    double peny;
    bool low=false;
    for (string line; getline(input, line);){
        Vector<string> vec = stringSplit(line, " ");
        for (int i = 0; i < vec.size(); i++){
            string s = toLowerCase(vec[i]);
            if(s=="pendown"){
                low=true;
            }
            else if (s =="moveabs"){
                if(low){
                    drawLine(penx, peny, stringToReal(vec[i+1]), stringToReal(vec[i+2]), pen);
                }
                penx = stringToReal(vec[i+1]);
                peny = stringToReal(vec[i+2]);

                break;
            }
            else if(s=="moverel"){
                penx+=stringToReal(vec[i+1]);
                peny+=stringToReal(vec[i+2]);
                break;
            }
            else if(s=="pencolor"){
                pen.color=vec[i+1];
            }
            else if (s=="penup"){
                low=false;
            }
            else if(s=="penwidth"){
                pen.width=stringToReal(vec[i+1]);
            }

        }
    }
}
