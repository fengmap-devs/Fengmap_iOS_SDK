//
//  FMKMathTool.h
//  FMMapKit
//
//  Created by smallLabel on 2018/3/14.
//  Copyright © 2018年 Fengmap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FMKGeometry.h"

/**
 一些向量计算函数
 */
@interface FMKMathTool : NSObject

/**
 计算两个地图坐标点的直线距离
 
 如果以fengmap坐标参与计算，结果为米制单位
 @param point1 地图坐标点1
 @param point2 地图坐标点2
 @return 两点直线距离
 */
double calculateTwoMapPointsDistance(FMKMapPoint point1, FMKMapPoint point2);

/**
 判断两个向量的夹角是否超过限定值
 
 @warning 若存在零向量，返回true
 @param vector1 向量1
 @param vector2 向量2
 @param limit 夹角限定值，单位度
 @return 比较结果 true：超出限定值
 */
bool twoVectorsAngleOverLimit(FMKMapPoint vector1, FMKMapPoint vector2, double limit);


/**
 计算向量的长度
 
 @param vector 向量
 @return 向量长度
 */
double calculateVectorLength(FMKMapPoint vector);

/**
 计算两个向量的夹角
 
 @warning 若存在零向量，返回360；
 @param vector1 向量1
 @param vector2 向量2
 @return 两个向量的夹角 计算结果为向量2相对向量1的夹角，结果夹角范围为-180-180度，左负右正
 */
double twoVectorsAngle(FMKMapPoint vector1, FMKMapPoint vector2);

/**
 判断两个点是不是近似同一个点，精确到小数点后一位

 @param mapPoint1 点1
 @param mapPoint2 点2
 @return 返回判断结果，若是，则返回true
 */
bool isSamePoint(FMKMapPoint mapPoint1, FMKMapPoint mapPoint2);

/**
 获取向量的点积
 
 @param vector1 向量1
 @param vector2 向量2
 @return 点积结果
 */
double twoVectorsDotProduct(FMKMapPoint vector1, FMKMapPoint vector2);

/**
 计算两个向量的叉乘
 
 @param vector1 向量1
 @param vector2 向量2
 @return 叉乘结果
 */
double twoVectorsVectorProduct(FMKMapPoint vector1, FMKMapPoint vector2);

/**
 两点线段向量化

 @param point1 点1
 @param point2 点2
 @return 点2指向点1构成的向量
 */
FMKMapPoint vectorization(FMKMapPoint point1, FMKMapPoint point2);

/**
 已废弃

 @param mapPoint1 点1
 @param mapPoint2 点2
 @return 两点距离
 */
+ (double)calculateTwoMapPointsDistanceWithPoint1:(FMKMapPoint)mapPoint1 point2:(FMKMapPoint)mapPoint2 DEPRECATED_MSG_ATTRIBUTE(" please use function calculateTwoMapPointsDistance()");

@end
