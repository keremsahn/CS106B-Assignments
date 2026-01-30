/*
 * File: grammarsolver.cpp
 * --------------------------
 * Name:
 * Section leader:
 * This file contains grammar generating code for CS106B.
 */

#include "grammarsolver.h"

using namespace std;

/**
 * Generates grammar for a given symbol a certain number of times given
 * a BNF input file.
 *
 * This will be called by grammarmain.cpp.
 *
 * @param input - Input stream of BNF file.
 * @param symbol - Symbol to generate
 * @param times - Number of times grammar is generated
 * @return Vector of strings of size times with random generations of symbol
 */

Map<string, Vector<string>> read_file(istream& input){
    string s;
    Map<string, Vector<string>> expr;
    while(getline(input, s)){
        Vector<string> tokens = stringSplit(s, "::=");
        if (tokens.size() < 2){
            continue;
        }
        string key = tokens[0];
        if(expr.containsKey(key) || key==""){
            throw "error";
        }
        tokens = stringSplit(tokens[1], "|");
        for(string& el : tokens){
            el = trim(el);
        }
        expr.put(key, tokens);
    }
    return expr;
}
string rec(Map<string, Vector<string>>& expr, string symbol){
    if(!expr.containsKey(symbol)){
        if(stringContains(symbol, " ")){
            Vector<string> n = stringSplit(symbol, " ");
            string total="";
            for(string& el : n){
                total+=" ";
                total+=rec(expr, el);
            }
            return total;
        }
        return symbol;
    }
    else{
        string total="";
        int ind = randomInteger(0, expr[symbol].size()-1);
        return total+" " + rec(expr, expr[symbol][ind]);
    }
}
Vector<string> grammarGenerate(istream& input, string symbol, int times) {
    // TODO: write this function

    Map<string, Vector<string>> expr = read_file(input);
    Vector<string> possibilities;
    for(int i = 0; i < times; i++){
        string s = trim(rec(expr, symbol));
        possibilities.add(s);
    }
    return possibilities;

}
