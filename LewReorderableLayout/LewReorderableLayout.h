//
//  LewReorderableLayout.h
//  LewPhotoBrowser
//
//  Created by pljhonglu on 15/5/18.
//  Copyright (c) 2015年 pljhonglu. All rights reserved.
//

#import <UIKit/UIKit.h>

//允许拖动排序的拖动方向
typedef NS_ENUM(NSInteger, DragDirectionType)
{
    DragDirectionTypeAll = 0,       //不限制拖动方向
    DragDirectionTypeHorizontal =1, //只能横向拖动
    DragDirectionTypeVertical =2    //只能纵向拖动
};

@protocol LewReorderableLayoutDataSource <UICollectionViewDataSource>

@required

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath;

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section;

@optional

- (CGFloat)reorderingItemAlpha:(UICollectionView * )collectionview inSection:(NSInteger)section; //Default 0.

- (UIEdgeInsets)scrollTrigerEdgeInsetsInCollectionView:(UICollectionView *)collectionView;

- (UIEdgeInsets)scrollTrigerPaddingInCollectionView:(UICollectionView *)collectionView;

- (CGFloat)scrollSpeedValueInCollectionView:(UICollectionView *)collectionView;

@end

@protocol LewReorderableLayoutDelegate <UICollectionViewDelegateFlowLayout>

@optional

- (void)collectionView:(UICollectionView *)collectionView itemAtIndexPath:(NSIndexPath *)fromIndexPath willMoveToIndexPath:(NSIndexPath *)toIndexPath;

- (void)collectionView:(UICollectionView *)collectionView itemAtIndexPath:(NSIndexPath *)fromIndexPath didMoveToIndexPath:(NSIndexPath *)toIndexPath;

- (BOOL)collectionView:(UICollectionView *)collectionView canMoveItemAtIndexPath:(NSIndexPath *)indexPath;

- (BOOL)collectionView:(UICollectionView *)collectionView itemAtIndexPath:(NSIndexPath *)fromIndexPath canMoveToIndexPath:(NSIndexPath *)toIndexPath;

- (void)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout willBeginDraggingItemAtIndexPath:(NSIndexPath *)indexPath;

- (void)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout didBeginDraggingItemAtIndexPath:(NSIndexPath *)indexPath;

- (void)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout willEndDraggingItemAtIndexPath:(NSIndexPath *)indexPath;

- (void)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout didEndDraggingItemAtIndexPath:(NSIndexPath *)indexPath;

@end


@interface LewReorderableLayout : UICollectionViewFlowLayout<UIGestureRecognizerDelegate>

@property (nonatomic, weak)id<LewReorderableLayoutDelegate> delegate;
@property (nonatomic, weak)id<LewReorderableLayoutDataSource> dataSource;
@property (nonatomic, strong)UILongPressGestureRecognizer *longPress;
@property (nonatomic, strong)UIPanGestureRecognizer *panGesture;

//支持拖动的方向
@property (nonatomic, assign)DragDirectionType dragDirection;

@end