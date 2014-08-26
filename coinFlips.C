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
    int finalTwo[2]={0};
    
    double probOfWinning[17]={0};
    /*
    for(int n=1;n<16;n++){
        probOfWinning[n]=(17-n)/16.;
        cerr<<probOfWinning[n]<<endl;
    }
     */
    double heads,tails;
    int winCount=0;
    double mu,sigma,epsilon;
    int it=10000;
    mu=.33;
    double sum;
    sigma=mu*(1-mu);
    for(int k=0;k<100;k++){
        heads=0;
        tails=0;
        sum=0;
        for(int l=0;l<it;l++){
            rand=r.Rndm();
            sum+=rand;
            if(rand<.33){
                heads++;
            }
            else{tails++;}
        }
        heads=heads/it;
        
        cerr<<" heads: "<<heads<<" tails: "<<tails/it<<endl;
        cerr<<"average sum was "<<sum/it<<endl;
        if(sum/it<.33){
            winCount++;
        }
        
    }
    cerr<<"win count "<<winCount<<" "<<winCount<<"% of the time"<<endl;

}
