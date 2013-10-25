%----------------------------------------------------------------------------------
% Matlab example file test_function.m
%
% This file demonstartes how to create a simple utility function.
% When calling test_function(...) from the Matlab prompt or another
% Matlab file, the following code will be executed.
%
% Andreas Freise 20.09.2011
%----------------------------------------------------------------------------------

function output=test_function(input)
  
  % element-wise squaring of the vector/matrix/scalar called `input'
  output=input.*input; 
  