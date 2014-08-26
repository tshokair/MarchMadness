//this algorithm uses the difference between probabilities of winning to deterimine a winner

{
    
  gROOT->SetStyle("Plain");
    TRandom3 r(0); // generate a number in interval ]0,1] (0 is excluded)
    r.Rndm();
    double rand;
    rand=r.Rndm();
    cerr<<rand<<endl;
    int roundOneWinners[4][8]={0};
    int roundTwoWinners[4][4]={0};
    int roundThreeWinners[4][2]={0};
    int finalFour[4]={0};
    int finalTwo[2]={}0;
    
    double probOfWinning[17]={0};
    
    for(int n=1;n<16;n++){
        probOfWinning[n]=(17-n)/16.;
        cerr<<probOfWinning[n]<<endl;
    }
    
    cerr<<"round one"<<endl;
    for(int j=0;j<4;j++){
        cerr<<"Part "<<j+1<<endl;
    
        
            rand= r.Rndm();
            if( rand >probOfWinning[16] ){
                roundOneWinners[j][0]=1;
            }
            else{
                roundOneWinners[j][0]=16;
            }
        cerr<<"In match 1 vs. 16 winner is "<<roundOneWinners[j][0]<<endl;
            rand= r.Rndm();
            if( rand >probOfWinning[9] ){
                roundOneWinners[j][1]=8;
            }
            else{
                roundOneWinners[j][1]=9;
            }
        cerr<<"In match 8 vs. 9 winner is "<<roundOneWinners[j][1]<<endl;
        rand= r.Rndm();
        if( rand >probOfWinning[12] ){
            roundOneWinners[j][2]=5;
        }
        else{
            roundOneWinners[j][2]=12;
        }
        cerr<<"In match 5 vs. 12 winner is "<<roundOneWinners[j][2]<<endl;
        rand= r.Rndm();
        if( rand >probOfWinning[13] ){
            roundOneWinners[j][3]=4;
        }
        else{
            roundOneWinners[j][3]=13;
        }
        cerr<<"In match 4 vs. 13 winner is "<<roundOneWinners[j][3]<<endl;
        rand= r.Rndm();
        if( rand >probOfWinning[11] ){
            roundOneWinners[j][4]=6;
        }
        else{
            roundOneWinners[j][4]=11;
        }
        cerr<<"In match 6 vs. 11 winner is "<<roundOneWinners[j][4]<<endl;
        rand= r.Rndm();
        if( rand >probOfWinning[14] ){
            roundOneWinners[j][5]=3;
        }
        else{
            roundOneWinners[j][5]=14;
        }
        cerr<<"In match 3 vs. 14 winner is "<<roundOneWinners[j][5]<<endl;
        rand= r.Rndm();
        if( rand >probOfWinning[10] ){
            roundOneWinners[j][6]=7;
        }
        else{
            roundOneWinners[j][6]=10;
        }
        cerr<<"In match 7 vs. 10 winner is "<<roundOneWinners[j][6]<<endl;
        rand= r.Rndm();
        if( rand >probOfWinning[15] ){
            roundOneWinners[j][7]=2;
        }
        else{
            roundOneWinners[j][7]=15;
        }
        cerr<<"In match 2 vs. 15 winner is "<<roundOneWinners[j][7]<<endl;
        
    }
    cerr<<"round two"<<endl;
    double tempP1=0;
    for(int j=0;j<4;j++){
        cerr<<"Part "<<j+1<<endl;
        
        for(int i=0;i<4;i++){
            rand= r.Rndm();

            tempP1=TMath::Abs(probOfWinning[roundOneWinners[j][2*i+1]]-probOfWinning[roundOneWinners[j][2*i]]);
            if( rand <tempP1 ){
                roundTwoWinners[j][i]=roundOneWinners[j][2*i];
            }
            else{
                roundTwoWinners[j][i]=roundOneWinners[j][2*i+1];
            }
            
            cerr<<"In match "<<roundOneWinners[j][2*i]<<" vs. "<<roundOneWinners[j][2*i+1]<<", winner is "<<roundTwoWinners[j][i]<<endl;
            
        }
    }
    
    cerr<<"round three"<<endl;
    double tempP2=0;
    for(int j=0;j<4;j++){
        cerr<<"Part "<<j+1<<endl;
        
        for(int i=0;i<2;i++){
            rand= r.Rndm();
            tempP2=TMath::Abs(probOfWinning[roundTwoWinners[j][2*i]]-probOfWinning[roundTwoWinners[j][2*i+1]]);
            if( rand <tempP2 ){
                roundThreeWinners[j][i]=roundTwoWinners[j][2*i];
            }
            else{
                roundThreeWinners[j][i]=roundTwoWinners[j][2*i+1];
            }
            cerr<<"In match "<<roundTwoWinners[j][2*i]<<" vs. "<<roundTwoWinners[j][2*i+1]<<", winner is "<<roundThreeWinners[j][i]<<endl;
            
        }
    }
    
    cerr<<"round four"<<endl;
    double tempP3=0;
    for(int j=0;j<4;j++){
        cerr<<"Part "<<j+1<<endl;
        tempP3=TMath::Abs(probOfWinning[roundTwoWinners[j][0]]>probOfWinning[roundTwoWinners[j][1]]);
            rand= r.Rndm();
            if( rand <tempP3){
                finalFour[j]=roundThreeWinners[j][0];
            }
            else{
                finalFour[j]=roundThreeWinners[j][1];
            }
            cerr<<"In match "<<roundThreeWinners[j][0]<<" vs. "<<roundThreeWinners[j][1]<<", winner is "<<finalFour[j]<<endl;
        
    }
    


}
