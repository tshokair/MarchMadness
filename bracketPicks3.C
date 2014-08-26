//this algorithm uses the weighted difference between evenness in probabilities of winning to deterimine a winner offset


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
    
    for(int n=1;n<17;n++){
        probOfWinning[n]=(17-n)/16.;
        //cerr<<probOfWinning[n]<<endl;
    }
    
    cerr<<"round one"<<endl;
    //chaos is allowed in round 1, giving all teams at least a 7% chance of winning
    for(int j=0;j<4;j++){
        cout<<location[j]<<endl;
    
        
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
            
            tempP1=TMath::Abs((17-roundOneWinners[j][2*i+1])*(17-roundOneWinners[j][2*i+1])/16.0-(17-roundOneWinners[j][2*i])*(17-roundOneWinners[j][2*i])/16.0);
            tempP1=tempP1/32.0+0.5;
            if(roundOneWinners[j][2*i]< roundOneWinners[j][2*i+1]){
                favorite=roundOneWinners[j][2*i];
                underdog=roundOneWinners[j][2*i+1];
            }
            else{
                underdog=roundOneWinners[j][2*i];
                favorite=roundOneWinners[j][2*i+1];
            }
            if( rand <tempP1 ){
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
            tempP2=TMath::Abs((17-roundTwoWinners[j][2*i+1])*(17-roundTwoWinners[j][2*i+1])/16.0-(17-roundTwoWinners[j][2*i])*(17-roundTwoWinners[j][2*i])/16.0);
            tempP2=tempP1/32.0+0.5;
            if(roundTwoWinners[j][2*i]< roundTwoWinners[j][2*i+1]){
                favorite=roundTwoWinners[j][2*i];
                underdog=roundTwoWinners[j][2*i+1];
            }
            else{
                underdog=roundTwoWinners[j][2*i];
                favorite=roundTwoWinners[j][2*i+1];
            }
            if( rand <tempP2 ){
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
        tempP3=TMath::Abs((17-roundThreeWinners[j][1])*(17-roundThreeWinners[j][1])/16.0-(17-roundThreeWinners[j][0])*(17-roundThreeWinners[j][0])/16.0);
        tempP3=tempP3/32.0+0.5;
        if(roundThreeWinners[j][0]< roundThreeWinners[j][1]){
            favorite=roundThreeWinners[j][0];
            underdog=roundThreeWinners[j][1];
        }
        else{
            underdog=roundThreeWinners[j][0];
            favorite=roundThreeWinners[j][1];
        }
            if( rand <tempP3){
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
    tempP=TMath::Abs((17-finalFour[0])*(17-finalFour[0])/16.0-(17-finalFour[3])*(17-finalFour[3])/16.0);
    tempP=tempP/32.0+0.5;
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
    if( rand <tempP){
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
    rand= r.Rndm();
    if( rand <tempP){
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
    tempP=TMath::Abs((17-finalTwo[0])*(17-finalTwo[0])/16.0-(17-finalTwo[1])*(17-finalTwo[1])/16.0);
    tempP=tempP/32.0+0.5;
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
    if( rand <tempP){
        cout<<"Champion is "<<favorite<<" from the "<<favLoc<<endl;
    }
    else{
        cout<<"Champion is "<<underdog<<" from the "<<undLoc<<endl;
    }
    cout<<"Score was "<<50+r.Rndm()*20<<" to "<<50+r.Rndm()*20<<endl;
}



