#include <opencv2/opencv.hpp>

int main() {
    // Image upload
    cv::Mat image = cv::imread("your_image_path.jpg");
    if (image.empty()) {
        std::cerr << "Unable to load image" << std::endl;
        return -1;
    }

    // Setting image gray
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // Searching
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(gray, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (size_t i = 0; i < contours.size(); ++i) {
        // Searching
        double epsilon = 0.02 * cv::arcLength(contours[i], true);
        std::vector<cv::Point> approx;
        cv::approxPolyDP(contours[i], approx, epsilon, true);

        if (approx.size() > 5) {
            cv::Point2f center;
            float radius;
            cv::minEnclosingCircle(contours[i], center, radius);

            cv::circle(image, center, static_cast<int>(radius), cv::Scalar(0, 255, 0), 2);
            cv::putText(image, "(" + std::to_string(static_cast<int>(center.x)) + ", " +
                        std::to_string(static_cast<int>(center.y)) + ")",
                        center, cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 0, 0), 2);
        }
    }

    // Result
    cv::imshow("Contours", image);
    cv::waitKey(0);

    return 0;
}
