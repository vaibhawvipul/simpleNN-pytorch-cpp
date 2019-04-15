#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <initializer_list>
#include "dataset.h"

void DataSet::ReadCSVFile(std::string file_name) {
  
  std::ifstream file(file_name.c_str());
  if (!file) {
    file.open(file_name.c_str());
  }
  if (!file) {
    std::cerr << "ERROR: No " << file_name << " found." << std::endl;
  }
  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string line;
  std::vector<std::string> lines;
  while(getline(buffer, line, '\n')) {
    lines.push_back(line);
    //std::cout << line << std::endl;
  }

  // the other lines contain the features for each flower
  for (int i = 1; i < lines.size(); ++i) {
    std::vector<float> features = ReadCSVLine(lines[i]);
    //std::cout << "line is : " << lines[i] << std::endl;
    //std::cout << "feature[0] is : " << features[0] << std::endl;
    //std::cout << "feature[1] is : " << features[1] << std::endl;
    //std::cout << "feature[2] is : " << features[2] << std::endl;
    //std::cout << "feature[3] is : " << features[3] << std::endl;
    //std::cout << "feature[4] is : " << features[4] << std::endl;
      x1_.push_back(features[0]);
      x2_.push_back(features[1]);
      x3_.push_back(features[2]);
      x4_.push_back(features[3]);
      y_.push_back(features[4]);
      /*if (features[4] == 1) {
        std::vector<float> y_feature;
        y_feature.push_back(0.0f);
        y_feature.push_back(0.0f);
        y_feature.push_back(0.0f);
        y_.push_back(y_feature);
      } else if (features[4] == 0.5f){
        std::vector<float> y_feature;
        y_feature.push_back(0.0f);
        y_feature.push_back(1.0f);
        y_feature.push_back(0.0f);
        y_.push_back(y_feature);
      } else {
        std::vector<float> y_feature;
        y_feature.push_back(0.0f);
        y_feature.push_back(0.0f);
        y_feature.push_back(1.0f);
        y_.push_back(y_feature);
      }*/
  }
}

std::vector<float> DataSet::ReadCSVLine(std::string line) {
  std::vector<float> line_data;
  std::stringstream lineStream(line);
  std::string cell;
  while(std::getline(lineStream, cell, ','))
  {
    if (cell!="setosa" && cell!="versicolor" && cell!="virginica") {
      line_data.push_back(std::stod(cell.c_str()));
    } else{
      if (cell=="setosa"){
        line_data.push_back(0.0f);
      } 
      else if (cell == "versicolor") {
        line_data.push_back(1.0f);
      } else {
        line_data.push_back(2.0f);
      }
    }
  }
  return line_data;
}

std::initializer_list<float> DataSet::input(float petal_length, float petal_width, float sepal_length, float sepal_width) {
  return {petal_length,petal_width,sepal_length,sepal_width};
}

std::string DataSet::output(std::vector<float> one_hot_encoding_species) {
  if (one_hot_encoding_species[0]==1){
    return "setosa";
  } else if (one_hot_encoding_species[1]==1){
    return "versicolor";
  } else {
    return "virginica";
  }
}