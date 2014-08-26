//this algorithm uses different probailities for each round


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
    
    double probOfWinning[17][5]={0};
    TString location[4];
    //ofstream screen;
    location[0]="south";
    location[1]="west";
    location[2]="midwest";
    location[3]="east";
    
    //probability of advancing in each round given http://theweek.com/article/index/258018/heres-definitive-proof-that-you-should-pick-a-1-seed-to-win-your-march-madness-bracket
    //1 seed
    probOfWinning[1][1]=.999;
    probOfWinning[1][2]=0.9;
    probOfWinning[1][3]=0.7;
    probOfWinning[1][4]=0.4;
    //2 seed
    probOfWinning[2][1]=.95;
    probOfWinning[2][2]=0.65;
    probOfWinning[2][3]=0.45;
    probOfWinning[2][4]=0.2;
    //3 seed
    probOfWinning[3][1]=.9;
    probOfWinning[3][2]=0.52;
    probOfWinning[3][3]=0.28;
    probOfWinning[3][4]=0.11;
    //4 seed
    probOfWinning[4][1]=.78;
    probOfWinning[4][2]=0.45;
    probOfWinning[4][3]=0.18;
    probOfWinning[4][4]=0.15;
    //5 seed
    probOfWinning[5][1]=.65;
    probOfWinning[5][2]=0.33;
    probOfWinning[5][3]=0.08;
    probOfWinning[5][4]=0.05;
    //6 seed
    probOfWinning[6][1]=.65;
    probOfWinning[6][2]=0.35;
    probOfWinning[6][3]=0.18;
    probOfWinning[6][4]=0.025;
    //7 seed
    probOfWinning[7][1]=.6;
    probOfWinning[7][2]=0.18;
    probOfWinning[7][3]=0.07;
    probOfWinning[7][4]=0.005;
    //8 seed
    probOfWinning[8][1]=.5;
    probOfWinning[8][2]=0.1;
    probOfWinning[8][3]=0.08;
    probOfWinning[8][4]=0.04;
    //9 seed
    probOfWinning[9][1]=.55;
    probOfWinning[9][2]=0.07;
    probOfWinning[9][3]=0.02;
    probOfWinning[9][4]=0.01;
    //10 seed
    probOfWinning[10][1]=.3;
    probOfWinning[10][2]=0.18;
    probOfWinning[10][3]=0.07;
    probOfWinning[10][4]=0.005;
    //11 seed
    probOfWinning[11][1]=.33;
    probOfWinning[11][2]=0.14;
    probOfWinning[11][3]=0.05;
    probOfWinning[11][4]=0.03;
    //12 seed
    probOfWinning[12][1]=.35;
    probOfWinning[12][2]=0.175;
    probOfWinning[12][3]=0.01;
    probOfWinning[12][4]=0.005;
    //13 seed
    probOfWinning[13][1]=.21;
    probOfWinning[13][2]=0.07;
    probOfWinning[13][3]=0.005;
    probOfWinning[13][4]=0.005;
    //14 seed
    probOfWinning[14][1]=.16;
    probOfWinning[14][2]=0.02;
    probOfWinning[14][3]=0.005;
    probOfWinning[14][4]=0.005;
    //15 seed
    probOfWinning[15][1]=.05;
    probOfWinning[15][2]=0.01;
    probOfWinning[15][3]=0.005;
    probOfWinning[15][4]=0.005;
    //16 seed
    probOfWinning[16][1]=0.001;
    probOfWinning[16][2]=0.001;
    probOfWinning[16][3]=0.001;
    probOfWinning[16][4]=0.001;
    
    cerr<<"round one"<<endl;
    //chaos is allowed in round 1, giving all teams at least a 7% chance of winning
    for(int j=0;j<4;j++){
        cout<<location[j]<<endl;
    
        
            rand= r.Rndm();
            if( rand >probOfWinning[16][1] ){
                roundOneWinners[j][0]=1;
            }
            else{
                roundOneWinners[j][0]=16;
            }
        cerr<<"In match 1 vs. 16 winner is "<<roundOneWinners[j][0]<<endl;
            rand= r.Rndm();
            if( rand >probOfWinning[9][1] ){
                roundOneWinners[j][1]=8;
            }
            else{
                roundOneWinners[j][1]=9;
            }
        cerr<<"In match 8 vs. 9 winner is "<<roundOneWinners[j][1]<<endl;
        rand= r.Rndm();
        if( rand >probOfWinning[12][1] ){
            roundOneWinners[j][2]=5;
        }
        else{
            roundOneWinners[j][2]=12;
        }
        cerr<<"In match 5 vs. 12 winner is "<<roundOneWinners[j][2]<<endl;
        rand= r.Rndm();
        if( rand >probOfWinning[13][1] ){
            roundOneWinners[j][3]=4;
        }
        else{
            roundOneWinners[j][3]=13;
        }
        cerr<<"In match 4 vs. 13 winner is "<<roundOneWinners[j][3]<<endl;
        rand= r.Rndm();
        if( rand >probOfWinning[11][1] ){
            roundOneWinners[j][4]=6;
        }
        else{
            roundOneWinners[j][4]=11;
        }
        cerr<<"In match 6 vs. 11 winner is "<<roundOneWinners[j][4]<<endl;
        rand= r.Rndm();
        if( rand >probOfWinning[14][1] ){
            roundOneWinners[j][5]=3;
        }
        else{
            roundOneWinners[j][5]=14;
        }
        cerr<<"In match 3 vs. 14 winner is "<<roundOneWinners[j][5]<<endl;
        rand= r.Rndm();
        if( rand >probOfWinning[10][1]){
            roundOneWinners[j][6]=7;
        }
        else{
            roundOneWinners[j][6]=10;
        }
        cerr<<"In match 7 vs. 10 winner is "<<roundOneWinners[j][6]<<endl;
        rand= r.Rndm();
        if( rand >probOfWinning[15][1] ){
            roundOneWinners[j][7]=2;
        }
        else{
            roundOneWinners[j][7]=15;
        }
        cerr<<"In match 2 vs. 15 winner is "<<roundOneWinners[j][7]<<endl;
        
    }
    cerr<<"round two"<<endl;
    double tempP1=0;
    double tN;
    int favorite=0;
    int underdog=0;
    for(int j=0;j<4;j++){
        cout<<location[j]<<endl;
        
        for(int i=0;i<4;i++){
            rand= r.Rndm();
            //tN=(17-roundOneWinners[j][2*i+1])*probOfWinning[roundOneWinners[j][2*i+1]]-(17-roundOneWinners[j][2*i])*probOfWinning[roundOneWinners[j][2*i]];
            //cerr<<tN<<endl;
            //tempP1=TMAth::Abs(tN);
            
      
            if(roundOneWinners[j][2*i]< roundOneWinners[j][2*i+1]){
                favorite=roundOneWinners[j][2*i];
                underdog=roundOneWinners[j][2*i+1];
            }
            else{
                underdog=roundOneWinners[j][2*i];
                favorite=roundOneWinners[j][2*i+1];
            }
            if( rand >probOfWinning[underdog][2] ){
                roundTwoWinners[j][i]=favorite;
            }
            else{
                roundTwoWinners[j][i]=underdog;
            }
            //cerr<<"Favorite was "<<favorite<<" with probability of winning "<<tempP1<<" ran was "<<rand<<endl;
            cerr<<"In match "<<roundOneWinners[j][2*i]<<" vs. "<<roundOneWinners[j][2*i+1]<<", winner is "<<roundTwoWinners[j][i]<<endl;
            
        }
    }
    
    cerr<<"round three"<<endl;
    double tempP2=0;
    for(int j=0;j<4;j++){
        cout<<location[j]<<endl;
        
        for(int i=0;i<2;i++){
            rand= r.Rndm();
    
            if(roundTwoWinners[j][2*i]< roundTwoWinners[j][2*i+1]){
                favorite=roundTwoWinners[j][2*i];
                underdog=roundTwoWinners[j][2*i+1];
            }
            else{
                underdog=roundTwoWinners[j][2*i];
                favorite=roundTwoWinners[j][2*i+1];
            }
            if( rand >probOfWinning[underdog][3]  ){
                roundThreeWinners[j][i]=favorite;
            }
            else{
                roundThreeWinners[j][i]=underdog;
            }
            cerr<<"In match "<<roundTwoWinners[j][2*i]<<" vs. "<<roundTwoWinners[j][2*i+1]<<", winner is "<<roundThreeWinners[j][i]<<endl;
            
        }
    }
    
    cerr<<"round four"<<endl;
    double tempP3=0;
    for(int j=0;j<4;j++){
        cout<<location[j]<<endl;
            rand= r.Rndm();

        if(roundThreeWinners[j][0]< roundThreeWinners[j][1]){
            favorite=roundThreeWinners[j][0];
            underdog=roundThreeWinners[j][1];
        }
        else{
            underdog=roundThreeWinners[j][0];
            favorite=roundThreeWinners[j][1];
        }
            if( rand >probOfWinning[underdog][4] ){
                finalFour[j]=favorite;
            }
            else{
                finalFour[j]=underdog;
            }
            cerr<<"In match "<<roundThreeWinners[j][0]<<" vs. "<<roundThreeWinners[j][1]<<", winner is "<<finalFour[j]<<endl;
        
    }
    double tempP=0;
    TString favLoc;
    TString undLoc;
    TString winLocR;
    TString winLocL;
    cout<<"Entering Final Four"<<endl;
    cout<<location[0]<<" vs. " <<location[3]<<endl;

    if(finalFour[0]< finalFour[3]){
        favorite=finalFour[0];
        underdog=finalFour[3];
        favLoc=location[0];
        undLoc=location[3];
    }
    else{
        underdog=finalFour[0];
        favorite=finalFour[3];
        undLoc=location[0];
        favLoc=location[3];
    }
    rand= r.Rndm();
    if( rand >probOfWinning[underdog][4]){
        finalTwo[0]=favorite;
        winLocL=favLoc;
        cout<<"Winner is "<<favorite<<" from the "<<favLoc<<endl;

    }
    else{
        finalTwo[0]=underdog;
        winLocL=undLoc;
        cout<<"Winner is "<<underdog<<" from the "<<undLoc<<endl;

    }
    cout<<location[1]<<" vs. " <<location[2]<<endl;

    if(finalFour[1]< finalFour[2]){
        favorite=finalFour[1];
        underdog=finalFour[2];
        favLoc=location[1];
        undLoc=location[2];
    }
    else{
        underdog=finalFour[1];
        favorite=finalFour[2];
        undLoc=location[1];
        favLoc=location[2];
    }
    rand= r.Rndm();
    if( rand >probOfWinning[underdog][4]){
        finalTwo[1]=favorite;
        winLocR=favLoc;
        cout<<"Winner is "<<favorite<<" from the "<<favLoc<<endl;
    }
    else{
        finalTwo[1]=underdog;
        winLocR=undLoc;
        cout<<"Winner is "<<underdog<<" from the "<<undLoc<<endl;

    }
    cout<<"Championship Game"<<endl;
    cout<<winLocL<<" "<<finalTwo[0]<<" vs. "<<winLocR<<" "<<finalTwo[1]<<endl;

    if(finalTwo[0]< finalTwo[1]){
        favorite=finalTwo[0];
        underdog=finalTwo[1];
        favLoc=winLocL;
        undLoc=winLocR;
    }
    else{
        underdog=finalTwo[0];
        favorite=finalTwo[1];
        undLoc=winLocL;
        favLoc=winLocR;
    }
    rand= r.Rndm();
    if( rand >probOfWinning[underdog][4]){
        cout<<"Champion is "<<favorite<<" from the "<<favLoc<<endl;
    }
    else{
        cout<<"Champion is "<<underdog<<" from the "<<undLoc<<endl;
    }
    cout<<"Score was "<<50+r.Rndm()*20<<" to "<<50+r.Rndm()*20<<endl;
}



