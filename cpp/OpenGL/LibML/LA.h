#pragma once 

#include <ostream>
#include <string>
#include <vector>

class Mat;

float sigmoid(float x);
float sigmoidPrime(float x);

class Vec {
public:
  Vec(size_t size);
  Vec(const std::vector<float>& e);
  static Vec random(size_t size, float from, float to);
  static Vec sort(const Vec& v);

  Vec& operator+=(const Vec& rhs);
  Vec& operator-=(const Vec& rhs);

  Vec operator+(const Vec& other) const;
  Vec operator-(const Vec& other) const;
  Vec operator*(const Vec& other) const;
  Vec operator/(const Vec& other) const;

  Vec apply(float func(float x)) const;
  Vec operator*(float a) const;
  
  static float dot(const Vec& a, const Vec& b);
  friend std::ostream& operator<<(std::ostream &os, const Vec& v) {os << v.toString() ; return os;}
  friend std::istream& operator>> (std::istream &is, Vec &vec);
  const std::string toString() const;
  
  float get(size_t i) const {return e[i];}
  void set(size_t i, float v) {e[i] = v;}
  
  float operator[](size_t index) const {return e[index];}
  float& operator[](size_t index) {return e[index];}
  size_t size() const {return e.size();}

private:
  std::vector<float> e;
};



class Mat {
public:
  Mat(size_t sizeX, size_t sizeY);
  Mat(size_t sizeX, const std::vector<float>& e);
  Mat(const Mat& other);
  static Mat random(size_t sizeX, size_t sizeY, float from, float to);
  static Mat tensorProduct(const Vec& a, const Vec& b);

  Mat& operator+=(const Mat& rhs);
  Mat& operator-=(const Mat& rhs);

  Mat operator*(float a) const;
  
  Vec operator*(const Vec& v) const;

  friend std::ostream& operator<<(std::ostream &os, const Mat& m) {os << m.toString() ; return os;}
  friend std::istream& operator>> (std::istream &is, Mat &mat);
  const std::string toString() const;

  size_t getWidth() const {return sizeX;}
  size_t getHeight() const {return e.size()/sizeX;}
  
  Mat transpose() const;
  
private:
  std::vector<float> e;
  size_t sizeX;
    
  Vec row(size_t i) const;
    
};