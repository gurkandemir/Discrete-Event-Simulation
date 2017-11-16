//
// Created by user on 13.11.2017.
//
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>
#include <queue>
#include "Cashier.h"
#include "Barista.h"
#include "Customer.h"

using namespace std;

template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}

double round(double t){
    int temp=1000*t;
    if(temp%10>5)
        temp+=10;

    temp/=10;

    return temp/100.0;
}

void model1(){
    /*int maxCashQue=0;
    int maxBarQue=0;
    float last=0;
    while(!pq.empty()){
        Customer c=pq.top();
        int order=c.index;
        if(customer[order].getStatus()==1){
            int count=0;
            for(int i=0;i<cashier.size();i++){
                if(customer[order].getArrivalTime() >= cashier[i].getEndTime()) {
                    cashier[i].setAvailable(true);
                }
                if(cashier[i].getAvailable()){
                    cashier[i].setAvailable(false);
                    cashier[i].setEndTime(customer[order].getArrivalTime() + customer[order].getOrderTime());
                    cashier[i].setUtilization(cashier[i].getUtilization() + customer[order].getOrderTime());
                    customer[order].setBarArrival(cashier[i].getEndTime());
                    customer[order].cashierInt=i;
                    customer[order].setCurTime(customer[order].getBarArrival());
                    break;
                }
                else{
                    count++;
                }
            }

            if(count==cashier.size()) {
                cashierQ.push(customer[order]);
                if(cashierQ.size()>maxCashQue)
                    maxCashQue=cashierQ.size();
            }

            else{
                customer[order].setStatus(2);
                pq.push(customer[order]);
            }
        }
        else if(customer[order].getStatus()==2){
           if(!cashierQ.empty()){
               Customer c1=cashierQ.top();
               int index=customer[order].cashierInt;
               int order1=c1.index;
               cashier[index].setAvailable(false);
               cashier[index].setEndTime(cashier[index].getEndTime() + customer[order1].getOrderTime());
               cashier[index].setUtilization(cashier[index].getUtilization() + customer[order1].getOrderTime());
               customer[order1].setBarArrival(cashier[index].getEndTime());
               customer[order1].cashierInt=index;
               customer[order1].setCurTime(customer[order1].getBarArrival());
               customer[order1].setStatus(2);
               pq.push(customer[order1]);
               cashierQ.pop();
           }

            customer[order].setStatus(3);
            pq.push(customer[order]);

        }

        else if(customer[order].getStatus()==3){
            int count=0;
            for(int i=0;i<bar.size();i++){
                if(customer[order].getBarArrival() >= bar[i].getEndTime()) {
                    bar[i].setAvailable(true);
                }

                if(bar[i].getAvailable()){
                    bar[i].setAvailable(false);
                    bar[i].setEndTime(customer[order].getBarArrival() + customer[order].getBrewTime());
                    bar[i].setUtilization(bar[i].getUtilization() + customer[order].getBrewTime());
                    customer[order].setBarEnd(bar[i].getEndTime());
                    customer[order].setCurTime(customer[order].getBarEnd());
                    customer[order].barInt=i;
                    customer[order].bar=true;
                    last=customer[order].getBarEnd();
                    break;
                }
                else {
                    count++;
                }
            }

            if(count==bar.size()) {
                baristaQ.push(customer[order]);
                if(baristaQ.size()>maxBarQue)
                    maxBarQue=baristaQ.size();
            }

            else{
                customer[order].setStatus(4);
                pq.push(customer[order]);
            }
        }

        else{
            if(!baristaQ.empty()){
                Customer c1=baristaQ.top();
                int order1=c1.index;
                int index=customer[order].barInt;
                bar[index].setAvailable(false);
                bar[index].setEndTime(bar[index].getEndTime() + customer[order1].getBrewTime());
                bar[index].setUtilization(bar[index].getUtilization() + customer[order1].getBrewTime());
                customer[order1].setBarEnd(bar[index].getEndTime());
                customer[order1].barInt=(index);
                customer[order1].setCurTime(customer[order1].getBarEnd());
                customer[order1].setStatus(4);
                pq.push(customer[order1]);
                last=customer[order1].getBarEnd();
                baristaQ.pop();
            }
        }
        pq.pop();
    }*/
}

/*void model2(vector<Customer> customer, vector<Cashier> cashier, vector<Barista> bar, vector<priority_queue> queue, priority_queue<Customer,vector<Customer>,CustomCompare> pq, priority_queue<Customer,vector<Customer>,CustomCompare> cashierQ){
    int maxCashQue=0;
    int maxBarQue=0;
    float last=0;
    while(!pq.empty()){
        Customer c=pq.top();
        int order=c.index;
        if(customer[order].getStatus()==1){
            int count=0;
            for(int i=0;i<cashier.size();i++){
                if(customer[order].getArrivalTime() >= cashier[i].getEndTime()) {
                    cashier[i].setAvailable(true);
                }
                if(cashier[i].getAvailable()){
                    cashier[i].setAvailable(false);
                    cashier[i].setEndTime(customer[order].getArrivalTime() + customer[order].getOrderTime());
                    cashier[i].setUtilization(cashier[i].getUtilization() + customer[order].getOrderTime());
                    customer[order].setBarArrival(cashier[i].getEndTime());
                    customer[order].cashierInt=i;
                    customer[order].setCurTime(customer[order].getBarArrival());
                    break;
                }
                else{
                    count++;
                }
            }

            if(count==cashier.size()) {
                cashierQ.push(customer[order]);
                if(cashierQ.size()>maxCashQue)
                    maxCashQue=cashierQ.size();
            }

            else{
                customer[order].setStatus(2);
                pq.push(customer[order]);
            }
        }
        else if(customer[order].getStatus()==2){
            if(!cashierQ.empty()){
                Customer c1=cashierQ.top();
                int index=customer[order].cashierInt;
                int order1=c1.index;
                cashier[index].setAvailable(false);
                cashier[index].setEndTime(cashier[index].getEndTime() + customer[order1].getOrderTime());
                cashier[index].setUtilization(cashier[index].getUtilization() + customer[order1].getOrderTime());
                customer[order1].setBarArrival(cashier[index].getEndTime());
                customer[order1].cashierInt=index;
                customer[order1].setCurTime(customer[order1].getBarArrival());
                customer[order1].setStatus(2);
                pq.push(customer[order1]);
                cashierQ.pop();
            }

            customer[order].setStatus(3);
            pq.push(customer[order]);

        }

        else if(customer[order].getStatus()==3){
            int count=0;
            for(int i=0;i<bar.size();i++){
                if(i==customer[order].cashierInt/3) {
                    if (customer[order].getBarArrival() >= bar[i].getEndTime()) {
                        bar[i].setAvailable(true);
                    }

                    if (bar[i].getAvailable()) {
                        bar[i].setAvailable(false);
                        bar[i].setEndTime(customer[order].getBarArrival() + customer[order].getBrewTime());
                        bar[i].setUtilization(bar[i].getUtilization() + customer[order].getBrewTime());
                        customer[order].setBarEnd(bar[i].getEndTime());
                        customer[order].setCurTime(customer[order].getBarEnd());
                        customer[order].barInt = i;
                        customer[order].bar = true;
                        last = customer[order].getBarEnd();
                        break;
                    } else {
                        count++;
                    }
                }
            }

            if(count==1){
                queue[customer[order].cashierInt/3].push(customer[order]);
                if(queue[customer[order].cashierInt/3].size()>bar[customer[order].cashierInt/3].maxQue)
                    bar[customer[order].cashierInt/3].maxQue=queue[customer[order].cashierInt/3].size();
            }

            else{
                customer[order].setStatus(4);
                pq.push(customer[order]);
            }
        }

        else{
            if(!queue[customer[order].cashierInt/3].empty()){
                Customer c1=queue[customer[order].cashierInt/3].top();
                int order1=c1.index;
                int index=customer[order].barInt;
                bar[index].setAvailable(false);
                bar[index].setEndTime(bar[index].getEndTime() + customer[order1].getBrewTime());
                bar[index].setUtilization(bar[index].getUtilization() + customer[order1].getBrewTime());
                customer[order1].setBarEnd(bar[index].getEndTime());
                customer[order1].barInt=(index);
                customer[order1].setCurTime(customer[order1].getBarEnd());
                customer[order1].setStatus(4);
                pq.push(customer[order1]);
                last=customer[order1].getBarEnd();
                queue[customer[order].cashierInt/3].pop();
            }
        }
        pq.pop();
    }

    cout<<last<<endl;
    cout<<maxCashQue<<endl;
    for(int i=0;i<bar.size();i++)
        cout<<bar[i].maxQue<<endl;
    //cout<<maxBarQue<<endl;
    for(int i=0;i<cashier.size();i++){
        cout << cashier[i].utilizationTime / last << endl;
    }

    for(int i=0;i<bar.size();i++)
        cout<<bar[i].utilizationTime / last<<endl;

    for(int i=0;i<customer.size();i++)
        cout<<customer[i].getBarEnd()-customer[i].getArrivalTime()<<endl;
}*/
struct CustomCompare{
    bool operator()(const Customer& lhs, const Customer& rhs) {
        return lhs.curTime > rhs.curTime;
    }
};

struct CustomCompare1{
    bool operator()(const Customer& lhs, const Customer& rhs) {
        return lhs.price < rhs.price;
    }
};
int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 2;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;


    ifstream infile(argv[1]);
    string line = "";
    int n, islem;
    getline(infile, line);
    n = stoi(line);
    cout << "number of Cashier: " << n << endl;

    getline(infile, line);
    islem = stoi(line);
    cout << "number of Customer: " << islem << endl;

    vector<Cashier> cashier;
    vector<Customer> customer;
    vector<Barista> bar;
    vector<priority_queue<Customer,vector<Customer>,CustomCompare1>> queue;
    priority_queue<Customer,vector<Customer>, CustomCompare> pq;
    priority_queue<Customer,vector<Customer>, CustomCompare> cashierQ;
    priority_queue<Customer,vector<Customer>,CustomCompare1> baristaQ;

    for (int i = 0; i < n; i++) {
        Cashier a(i);
        cashier.push_back(a);
    }

    for (int i = 0; i < n / 3; i++) {
        Barista a(i);
        bar.push_back(a);
        priority_queue<Customer,vector<Customer>,CustomCompare1> baristaQ;
        queue.push_back(baristaQ);
    }

    for (int i = 0; i < islem; i++) {
        vector<string> words;
        getline(infile, line);
        split1(line, words);
        Customer c(i, stod(words[0]), stod(words[1]), stod(words[2]), stod(words[3]));
        pq.push(c);
        customer.push_back(c);
    }

    cout << "input file has been read" << endl;

    int maxCashQue=0;
    int maxBarQue=0;
    double last=0;
    while(!pq.empty()){
        Customer c=pq.top();
        int order=c.index;
        if(customer[order].getStatus()==1){
            int count=0;
            for(int i=0;i<cashier.size();i++){
                if(customer[order].getArrivalTime() >= cashier[i].getEndTime()) {
                    cashier[i].setAvailable(true);
                }
                if(cashier[i].getAvailable()){
                    cashier[i].setAvailable(false);
                    cashier[i].setEndTime(customer[order].getArrivalTime() + customer[order].getOrderTime());
                    cashier[i].setUtilization(cashier[i].getUtilization() + customer[order].getOrderTime());
                    customer[order].setBarArrival(cashier[i].getEndTime());
                    customer[order].cashierInt=i;
                    customer[order].setCurTime(customer[order].getBarArrival());
                    break;
                }
                else{
                    count++;
                }
            }

            if(count==cashier.size()) {
                cashierQ.push(customer[order]);
                if(cashierQ.size()>maxCashQue)
                    maxCashQue=cashierQ.size();
            }

            else{
                customer[order].setStatus(2);
                pq.push(customer[order]);
            }
        }
        else if(customer[order].getStatus()==2){
            if(!cashierQ.empty()){
                Customer c1=cashierQ.top();
                int index=customer[order].cashierInt;
                int order1=c1.index;
                cashier[index].setAvailable(false);
                cashier[index].setEndTime(cashier[index].getEndTime() + customer[order1].getOrderTime());
                cashier[index].setUtilization(cashier[index].getUtilization() + customer[order1].getOrderTime());
                customer[order1].setBarArrival(cashier[index].getEndTime());
                customer[order1].cashierInt=index;
                customer[order1].setCurTime(customer[order1].getBarArrival());
                customer[order1].setStatus(2);
                pq.push(customer[order1]);
                cashierQ.pop();
            }

            customer[order].setStatus(3);
            pq.push(customer[order]);

        }

        else if(customer[order].getStatus()==3){
            int count=0;
            for(int i=0;i<bar.size();i++){
                if(i==customer[order].cashierInt/3) {
                    if (customer[order].getBarArrival() >= bar[i].getEndTime()) {
                        bar[i].setAvailable(true);
                    }

                    if (bar[i].getAvailable()) {
                        bar[i].setAvailable(false);
                        bar[i].setEndTime(customer[order].getBarArrival() + customer[order].getBrewTime());
                        bar[i].setUtilization(bar[i].getUtilization() + customer[order].getBrewTime());
                        customer[order].setBarEnd(bar[i].getEndTime());
                        customer[order].setCurTime(customer[order].getBarEnd());
                        customer[order].barInt = i;
                        customer[order].bar = true;
                        last = customer[order].getBarEnd();
                        break;
                    } else {
                        count++;
                    }
                }
            }

            if(count==1){
                queue[customer[order].cashierInt/3].push(customer[order]);
                if(queue[customer[order].cashierInt/3].size()>bar[customer[order].cashierInt/3].maxQue)
                    bar[customer[order].cashierInt/3].maxQue=queue[customer[order].cashierInt/3].size();
            }

            else{
                customer[order].setStatus(4);
                pq.push(customer[order]);
            }
        }

        else{
            if(!queue[customer[order].cashierInt/3].empty()){
                Customer c1=queue[customer[order].cashierInt/3].top();
                int order1=c1.index;
                int index=customer[order].barInt;
                bar[index].setAvailable(false);
                bar[index].setEndTime(bar[index].getEndTime() + customer[order1].getBrewTime());
                bar[index].setUtilization(bar[index].getUtilization() + customer[order1].getBrewTime());
                customer[order1].setBarEnd(bar[index].getEndTime());
                customer[order1].barInt=(index);
                customer[order1].setCurTime(customer[order1].getBarEnd());
                customer[order1].setStatus(4);
                pq.push(customer[order1]);
                last=customer[order1].getBarEnd();
                queue[customer[order].cashierInt/3].pop();
            }
        }
        pq.pop();
    }

    cout<<round(last)<<endl;
    cout<<maxCashQue<<endl;
    for(int i=0;i<bar.size();i++)
        cout<<bar[i].maxQue<<endl;
    //cout<<maxBarQue<<endl;
    for(int i=0;i<cashier.size();i++){
        cout << round(cashier[i].utilizationTime / last) << endl;
    }

    for(int i=0;i<bar.size();i++)
        cout<<round(bar[i].utilizationTime / last)<<endl;

    for(int i=0;i<customer.size();i++)
        cout<<round(customer[i].getBarEnd()-customer[i].getArrivalTime())<<endl;

}