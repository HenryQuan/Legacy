//
//  BMIresult.m
//  BMI
//
//  Created by 权一恒 on 17/03/14.
//  Copyright (c) 2014年 HenryQuan. All rights reserved.
//

#import "BMIresult.h"

NSString *kg;
NSString *cm;
NSString *bmiresult;
NSString *idealresult;
float weight;
float height;
float bmi;
float ideal;

@interface BMIresult ()

@end

@implementation BMIresult

@synthesize dataweight;
@synthesize dataheight;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    if ([dataheight  isEqual: @""]||[dataweight  isEqual: @""])
    {
        self.thecomment.text = [NSString stringWithFormat:@"请先输入你的身高与体重^_^"];
        self.BMIresult.text = [NSString stringWithFormat:@"-_-"];
        self.heighttext.text = [NSString stringWithFormat:@"..."];
        self.weighttext.text = [NSString stringWithFormat:@"..."];
    }
    else if ([dataheight  isEqual: @"0"]||[dataweight  isEqual: @"0"])
    {
        self.BMIresult.text = [NSString stringWithFormat:@"0"];
        self.thecomment.text = [NSString stringWithFormat:@"不可思议的数值+_+"];
    }
    else
    {
    kg = [NSString stringWithFormat:@"%@  kg",dataweight];
    cm = [NSString stringWithFormat:@"%@  cm",dataheight];
    self.heighttext.text = cm;
    self.weighttext.text = kg;
    weight = [dataweight floatValue];
    height = [dataheight floatValue];
    bmi = ((weight)/((height/100)*(height/100)));
    bmiresult = [NSString stringWithFormat:@"%1.2f",bmi];
    self.BMIresult.text = bmiresult;
    ideal = (height - 110);
    if (bmi <= 18.50)
    {
        self.thecomment.text = [NSString stringWithFormat:@"你的体重过轻\r\n你的理想体重是\r\n%1.0f kg",ideal];
    }
    if (bmi > 18.50 && bmi <= 25.00)
    {
        self.thecomment.text = [NSString stringWithFormat:@"你的体重适中，请保持^_^\r\n你的理想体重是\r\n%1.0f kg",ideal];
    }
    if (bmi > 25.00 && bmi <= 35.00)
    {
        self.thecomment.text = [NSString stringWithFormat:@"你的体重过重，请多做练习 ^_^\r\n你的理想体重是\r\n%1.0f kg",ideal];
    }
    if (bmi > 35.00)
    {
        self.thecomment.text = [NSString stringWithFormat:@"你的体重......\r\n你的理想体重是\r\n%1.0f kg",ideal];
    }
    }
    
    [dataheight isEqual: @""];
    [dataweight isEqual: @""];
    [kg isEqual: @"" ];
    [cm isEqual: @""];
    [bmiresult isEqual: @""];
	// Do any additional setup after loading the view.
}

-(void)bannerViewDidLoadAd:(ADBannerView *)banner {
    
    // Creates animation.
    [UIView beginAnimations:nil context:nil];
    
    // Sets the duration of the animation to 1.
    [UIView setAnimationDuration:1];
    
    // Sets the alpha to 1.
    // We do this because we are going to have it set to 0 to start and setting it to 1 will cause the iAd to fade into view.
    [banner setAlpha:1];
    
    //  Performs animation.
    [UIView commitAnimations];
    
}

// Method is called when the iAd fails to load.
-(void)bannerView:(ADBannerView *)banner didFailToReceiveAdWithError:(NSError *)error {
    
    // Creates animation.
    [UIView beginAnimations:nil context:nil];
    
    // Sets the duration of the animation to 1.
    [UIView setAnimationDuration:1];
    
    // Sets the alpha to 0.
    // We do this because we are going to have it set to 1 to start and setting it to 0 will cause the iAd to fade out of view.
    [banner setAlpha:0];
    
    //  Performs animation.
    [UIView commitAnimations];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
