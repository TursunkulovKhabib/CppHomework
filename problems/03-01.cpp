#include <vector>
#include <algorithm>
#include <limits>

struct Rectangle {
    double left;
    double top;
    double right;
    double bottom;
    
    Rectangle(double l, double t, double r, double b) 
        : left(l), top(t), right(r), bottom(b) {}
    
    bool isEmpty() const {
        return left >= right || top >= bottom;
    }
    
    double area() const {
        if (isEmpty()) return 0.0;
        return (right - left) * (bottom - top);
    }
};

Rectangle intersection(const Rectangle& a, const Rectangle& b) {
    double interLeft = std::max(a.left, b.left);
    double interTop = std::max(a.top, b.top);
    double interRight = std::min(a.right, b.right);
    double interBottom = std::min(a.bottom, b.bottom);
    
    if (interLeft >= interRight || interTop >= interBottom) {
        return Rectangle(0, 0, 0, 0);
    }
    
    return Rectangle(interLeft, interTop, interRight, interBottom);
}

double intersectionArea(const std::vector<Rectangle>& rectangles) {
    if (rectangles.empty()) return 0.0;
    
    Rectangle current = rectangles[0];
    
    for (size_t i = 1; i < rectangles.size(); ++i) {
        current = intersection(current, rectangles[i]);
        
        if (current.isEmpty()) {
            return 0.0;
        }
    }
    
    return current.area();
}

Rectangle boundingBox(const std::vector<Rectangle>& rectangles) {
    if (rectangles.empty()) {
        return Rectangle(0, 0, 0, 0);
    }
    
    double minLeft = std::numeric_limits<double>::max();
    double minTop = std::numeric_limits<double>::max();
    double maxRight = std::numeric_limits<double>::lowest();
    double maxBottom = std::numeric_limits<double>::lowest();
    
    for (const auto& rect : rectangles) {
        if (!rect.isEmpty()) {
            minLeft = std::min(minLeft, rect.left);
            minTop = std::min(minTop, rect.top);
            maxRight = std::max(maxRight, rect.right);
            maxBottom = std::max(maxBottom, rect.bottom);
        }
    }
    
    if (minLeft == std::numeric_limits<double>::max()) {
        return Rectangle(0, 0, 0, 0);
    }
    
    return Rectangle(minLeft, minTop, maxRight, maxBottom);
}

int main() {
    return 0;
}
