//
//  BMIresult.h
//  BMI
//
//  Created by 权一恒 on 17/03/14.
//  Copyright (c) 2014年 HenryQuan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <iAd/iAd.h>

@interface BMIresult : UIViewController <ADBannerViewDelegate>

@property (weak, nonatomic) IBOutlet UILabel *heighttext;
@property (weak, nonatomic) IBOutlet UILabel *weighttext;
@property (weak, nonatomic) IBOutlet UILabel *BMIresult;
@property (weak, nonatomic) IBOutlet UILabel *thecomment;
@property (weak, nonatomic) NSString *dataweight;
@property (weak, nonatomic) NSString *dataheight;

@end
