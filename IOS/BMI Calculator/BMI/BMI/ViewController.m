//
//  ViewController.m
//  BMI
//
//  Created by 权一恒 on 16/03/14.
//  Copyright (c) 2014年 HenryQuan. All rights reserved.
//

#import "ViewController.h"
#import "BMIresult.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

-(void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    self.weight = @"";
    self.height = @"";
    if([segue.identifier isEqualToString:@"passing"])
    {
        self.weight = self.weightext.text;
        self.height = self.heightext.text;
        BMIresult *bodyweight = [segue destinationViewController];
        BMIresult *bodyheight = [segue destinationViewController];
        bodyweight.dataweight = self.weight;
        bodyheight.dataheight = self.height;
    }
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

- (IBAction)calcpressed:(id)sender
{
    [self.heightext resignFirstResponder];
    [self.weightext resignFirstResponder];
}

- (IBAction)cleanpressed:(id)sender
{
    self.heightext.text = @"";
    self.weightext.text = @"";
    [self.heightext resignFirstResponder];
    [self.weightext resignFirstResponder];
}

@end
