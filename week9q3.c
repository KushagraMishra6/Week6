#include<stdio.h>
typedef struct {
    int shapeType;
    union {
        float radius;
        struct {
            float length;
            float width;
        }Rectangle;
        struct {
            float base;
            float height;
        }Triangle;
    } dimensions;
} Shape;
int main(){
    Shape x;
    scanf("%d",&x.shapeType);
    switch(x.shapeType){
        case 2: scanf("%f",&x.dimensions.Rectangle.length);
                  scanf("%f",&x.dimensions.Rectangle.width);
                  printf("%.2f",x.dimensions.Rectangle.length*x.dimensions.Rectangle.width);
                  break;
        case 3: scanf("%f",&x.dimensions.Triangle.base);
                  scanf("%f",&x.dimensions.Triangle.height);
                  printf("%.2f",x.dimensions.Triangle.base*x.dimensions.Triangle.height*0.5);
                  break;
        case 1: scanf("%f",&x.dimensions.radius);
                  printf("%.2f",3.141593*x.dimensions.radius*x.dimensions.radius);  
                  break;
        default : printf("%d",-999);     
    }
}