//this algorithm uses the weighted difference between evenness in probabilities of winning to deterimine a winner offset. This attempt also runs a Monte Carlo method to determine the outcomes.


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
    TString location[4];
    //ofstream screen;
    location[0]="south";
    location[1]="west";
    location[2]="midwest";
    location[3]="east";
    double pAdv[17][5];
    //probability of advancing in each round given http://theweek.com/article/index/258018/heres-definitive-proof-that-you-should-pick-a-1-seed-to-win-your-march-madness-bracket
    //1 seed
    pAdv[1][1]=.999;
    pAdv[1][2]=0.9;
    pAdv[1][3]=0.7;
    pAdv[1][4]=0.4;
    //2 seed
    pAdv[2][1]=.95;
    pAdv[2][2]=0.65;
    pAdv[2][3]=0.45;
    pAdv[2][4]=0.2;
    //3 seed
    pAdv[3][1]=.9;
    pAdv[3][2]=0.52;
    pAdv[3][3]=0.28;
    pAdv[3][4]=0.11;
    //4 seed
    pAdv[4][1]=.78;
    pAdv[4][2]=0.45;
    pAdv[4][3]=0.18;
    pAdv[4][4]=0.15;
    //5 seed
    pAdv[5][1]=.65;
    pAdv[5][2]=0.33;
    pAdv[5][3]=0.08;
    pAdv[5][4]=0.05;
    //6 seed
    pAdv[6][1]=.65;
    pAdv[6][2]=0.35;
    pAdv[6][3]=0.18;
    pAdv[6][4]=0.025;
    //7 seed
    pAdv[7][1]=.6;
    pAdv[7][2]=0.18;
    pAdv[7][3]=0.07;
    pAdv[7][4]=0.005;
    //8 seed
    pAdv[8][1]=.5;
    pAdv[8][2]=0.1;
    pAdv[8][3]=0.08;
    pAdv[8][4]=0.04;
    //9 seed
    pAdv[9][1]=.55;
    pAdv[9][2]=0.07;
    pAdv[9][3]=0.02;
    pAdv[9][4]=0.01;
    //10 seed
    pAdv[10][1]=.3;
    pAdv[10][2]=0.18;
    pAdv[10][3]=0.07;
    pAdv[10][4]=0.005;
    //11 seed
    pAdv[11][1]=.33;
    pAdv[11][2]=0.14;
    pAdv[11][3]=0.05;
    pAdv[11][4]=0.03;
    //12 seed
    pAdv[12][1]=.35;
    pAdv[12][2]=0.175;
    pAdv[12][3]=0.01;
    pAdv[12][4]=0.005;
    //13 seed
    pAdv[13][1]=.21;
    pAdv[13][2]=0.07;
    pAdv[13][3]=0.005;
    pAdv[13][4]=0.005;
    //14 seed
    pAdv[14][1]=.16;
    pAdv[14][2]=0.02;
    pAdv[14][3]=0.005;
    pAdv[14][4]=0.005;
    //15 seed
    pAdv[15][1]=.05;
    pAdv[15][2]=0.01;
    pAdv[15][3]=0.005;
    pAdv[15][4]=0.005;
    //16 seed
    pAdv[16][1]=0.001;
    pAdv[16][2]=0.001;
    pAdv[16][3]=0.001;
    pAdv[16][4]=0.001;
    
    
    for(int n=1;n<17;n++){
        probOfWinning[n]=(17-n)*(17-n)/(16*16.);
        cerr<<probOfWinning[n]<<endl;
    }
    
    cerr<<"round one"<<endl;
    double heads=0;
    double tails=0;
    int it=100;
    double tProb=0;
    //chaos is allowed in round 1, giving all teams at least a 7% chance of winning
    for(int j=0;j<4;j++){
        cout<<location[j]<<endl;
    
        
            rand= r.Rndm();
        heads=0;
        tails=0;
        for (int n=0;n<it;n++){
            if(r.Rndm()<0.5){
                heads++;
            }
        }
        heads= heads*pAdv[16][1]*2;
        tProb=heads/it/1.0;
        cerr<<"Heads count "<<heads<<" "<<tProb<<" "<<pAdv[16][1]<<endl;
        if( tProb >pAdv[16][1] || tProb==0  ){
                roundOneWinners[j][0]=1;
            }
            else{
                roundOneWinners[j][0]=16;
            }
        cerr<<"In match 1 vs. 16 winner is "<<roundOneWinners[j][0]<<endl;
            rand= r.Rndm();
        heads=0;
        tails=0;
        for (int n=0;n<it;n++){
            if(r.Rndm()<pAdv[9][1]){
                heads++;
            }
        }
        //heads= heads*pAdv[9][1]*2;
        tProb=double(heads/it/1.0);
        cerr<<"Heads count "<<heads<<" "<<tProb<<" "<<pAdv[8][1]<<endl;
            if( tProb >pAdv[9][1] ){
                roundOneWinners[j][1]=8;
            }
            else{
                roundOneWinners[j][1]=9;
            }
        cerr<<"In match 8 vs. 9 winner is "<<roundOneWinners[j][1]<<endl;
        rand= r.Rndm();
        heads=0;
        tails=0;
        for (int n=0;n<it;n++){
            if(r.Rndm()<0.5){
                heads++;
            }
        }
        heads= heads*pAdv[12][1]*2;
        tProb=heads/it/1.0;
        cerr<<"Heads count "<<heads<<" "<<tProb<<endl;
        if( tProb >pAdv[12][1] ){
            roundOneWinners[j][2]=5;
        }
        else{
            roundOneWinners[j][2]=12;
        }
        cerr<<"In match 5 vs. 12 winner is "<<roundOneWinners[j][2]<<endl;
        rand= r.Rndm();
        heads=0;
        tails=0;
        for (int n=0;n<it;n++){
            if(r.Rndm()<0.5){
                heads++;
            }
        }
        heads= heads*pAdv[13][1]*2;
        tProb=heads/it/1.0;
        cerr<<"Heads count "<<heads<<" "<<tProb<<" "<<pAdv[13][1]<<endl;
        if( tProb >pAdv[13][1] ){
            roundOneWinners[j][3]=4;
        }
        else{
            roundOneWinners[j][3]=13;
        }
        cerr<<"In match 4 vs. 13 winner is "<<roundOneWinners[j][3]<<endl;
        rand= r.Rndm();
        heads=0;
        tails=0;
        for (int n=0;n<it;n++){
            if(r.Rndm()<0.5){
                heads++;
            }
        }
        heads= heads*pAdv[11][1]*2;
        tProb=heads/it/1.0;
        cerr<<"Heads count "<<heads<<" "<<tProb<<endl;
        if( tProb <pAdv[11][1] ){
            roundOneWinners[j][4]=6;
        }
        else{
            roundOneWinners[j][4]=11;
        }
        cerr<<"In match 6 vs. 11 winner is "<<roundOneWinners[j][4]<<endl;
        rand= r.Rndm();
        heads=0;
        tails=0;
        for (int n=0;n<it;n++){
            if(r.Rndm()<0.5){
                heads++;
            }
        }
        heads= heads*pAdv[14][1]*2;
        tProb=heads/it/1.0;
        cerr<<"Heads count "<<heads<<" "<<tProb<<endl;
        if( tProb >pAdv[14][1] ){
            roundOneWinners[j][5]=3;
        }
        else{
            roundOneWinners[j][5]=14;
        }
        cerr<<"In match 3 vs. 14 winner is "<<roundOneWinners[j][5]<<endl;
        rand= r.Rndm();
        heads=0;
        tails=0;
        for (int n=0;n<it;n++){
            if(r.Rndm()<0.5){
                heads++;
            }
        }
        heads= heads*pAdv[10][1]*2;
        tProb=heads/it/1.0;
        cerr<<"Heads count "<<heads<<" "<<tProb<<endl;
        if( tProb >pAdv[10][1] ){
            roundOneWinners[j][6]=7;
        }
        else{
            roundOneWinners[j][6]=10;
        }
        cerr<<"In match 7 vs. 10 winner is "<<roundOneWinners[j][6]<<endl;
        rand= r.Rndm();
        heads=0;
        tails=0;
        for (int n=0;n<it;n++){
            if(r.Rndm()<0.5){
                heads++;
            }
        }
        tProb=heads/it/1.0;
        heads= heads*pAdv[15][1]*2;
        cerr<<"Heads count "<<heads<<" "<<tProb<<endl;
        if( tProb >pAdv[15][1] ){
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

            if(roundOneWinners[j][2*i]< roundOneWinners[j][2*i+1]){
                favorite=roundOneWinners[j][2*i];
                underdog=roundOneWinners[j][2*i+1];
            }
            else{
                underdog=roundOneWinners[j][2*i];
                favorite=roundOneWinners[j][2*i+1];
            }
            heads=0;
            tails=0;
            for (int n=0;n<it;n++){
                if(r.Rndm()<pAdv[underdog][2]){
                    heads++;
                }
            }
            tProb=heads/it/1.0;
            //cerr<<"Heads count "<<heads<<" "<<tProb<<endl;
            if( tProb <pAdv[favorite][2] ){
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
           
            if(roundTwoWinners[j][2*i]< roundTwoWinners[j][2*i+1]){
                favorite=roundTwoWinners[j][2*i];
                underdog=roundTwoWinners[j][2*i+1];
            }
            else{
                underdog=roundTwoWinners[j][2*i];
                favorite=roundTwoWinners[j][2*i+1];
            }
            
            heads=0;
            tails=0;
            for (int n=0;n<it;n++){
                if(r.Rndm()<pAdv[underdog][3]){
                    heads++;
                }
            }
            tProb=heads/it/1.0;
            //cerr<<"Heads count "<<heads<<" "<<tProb<<endl;
            if( tProb <pAdv[favorite][3] ){
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
        heads=0;
        tails=0;
        for (int n=0;n<it;n++){
            if(r.Rndm()<pAdv[underdog][3]){
                heads++;
            }
        }
        tProb=heads/it/1.0;
        //cerr<<"Heads count "<<heads<<" "<<tProb<<endl;
        if( tProb <pAdv[favorite][4] ){
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

    heads=0;
    tails=0;
    for (int n=0;n<it;n++){
        if(r.Rndm()<pAdv[underdog][4]){
            heads++;
        }
    }
    tProb=heads/it/1.0;
    cerr<<"Heads count "<<heads<<" "<<tProb<<pAdv[favorite][4]<<endl;
    if( tProb <pAdv[favorite][4] ){
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
    tempP=TMath::Abs((17-finalFour[0])*(17-finalFour[0])/16.0-(17-finalFour[3])*(17-finalFour[3])/16.0);
    tempP=tempP/32.0+0.5;
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
    heads=0;
    tails=0;
    for (int n=0;n<it;n++){
        if(r.Rndm()<pAdv[underdog][4]){
            heads++;
        }
    }
    tProb=heads/it/1.0;
    //cerr<<"Heads count "<<heads<<" "<<tProb<<endl;
    if( tProb <pAdv[favorite][4] ){
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
    heads=0;
    tails=0;
    for (int n=0;n<it;n++){
        if(r.Rndm()<pAdv[underdog][4]){
            heads++;
        }
    }
    tProb=heads/it/1.0;
    //cerr<<"Heads count "<<heads<<" "<<tProb<<endl;
    if( tProb <pAdv[favorite][4] ){
        cout<<"Champion is "<<favorite<<" from the "<<favLoc<<endl;
    }
    else{
        cout<<"Champion is "<<underdog<<" from the "<<undLoc<<endl;
    }
    cout<<"Score was "<<50+r.Rndm()*20<<" to "<<50+r.Rndm()*20<<endl;
}



