//
//  FMKLabelLayer.h
//  FMMapKit
//
//  Created by fengmap on 16/3/7.
//  Copyright © 2016年 Fengmap. All rights reserved.
//

#import "FMKLayer.h"
@class FMKLabel;

/**
 图层名称显示字段选择
 */
typedef NS_ENUM(NSUInteger, FMKLabelField) {
    /// 模型名称显示内容为name字段
    FMKLABELFIELD_NAME = 0,
    /// 模型名称显示内容为ename字段
    FMKLABELFIELD_ENAME,
};

/**
 地图文本标签图层
 地图自有图层，不支持用户创建
 获取方式 FMKMap getLabelLayerByGroupID:
 */
@interface FMKLabelLayer : FMKLayer

+ (instancetype)new UNAVAILABLE_ATTRIBUTE;
- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 *  初始化label层
 *
 *  @param groupID label所在楼层
 *
 *  @return label管理层对象
 */
- (instancetype)initWithGroupID:(NSString *)groupID;

///文本标签图层所在楼层ID
@property(readonly)NSString * groupID;

/**
 模型名称显示字段切换，name字段和ename字段，字段属性为fmap数据制作过程中确定，SDK不可修改
 */
@property (nonatomic) FMKLabelField displayName;



/**
 *  根据文本内容获取文本对象
 *
 *  @param text 文本内容
 *
 *  @return 文本对象
 */
- (FMKLabel *)queryLabelByText:(NSString *)text;

@end
