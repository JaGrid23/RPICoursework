#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep 16 14:41:19 2019

@author: jaredgridley
The purpose of this program is to take input and then convert it and output the average speed and average pace. 
"""
import math

minutes = (input("Minutes ==> "))
print(minutes)

seconds = input("Seconds ==> ")
print(seconds)

miles = input("Miles ==> ")
print(miles)

target = input("Target Miles ==> ")
print(target)


def averagepace(miles, minutes, seconds):
     pace_toseconds = ((minutes) * 60) + (seconds)
     pace_inseconds = (pace_toseconds) / (miles)
     pace_minutes = pace_inseconds // 60
     pace_seconds = pace_inseconds % 60
     
     return "Pace is {0} minutes and {1} seconds per mile.".format(int(pace_minutes), math.floor(pace_seconds))

print_averagepace = averagepace(float(miles), int(minutes), int(seconds))

def averagespeed(miles, minutes, seconds):
    speed_hours = ((minutes) + ((seconds) / 60)) / 60
    speed_mph = miles / speed_hours
    
    return "Speed is {0:.2f} miles per hour.".format(speed_mph)

print_averagespeed = averagespeed(float(miles), int(minutes), int(seconds))

def targettime(target, miles, minutes, seconds):
    original_minutes = (minutes) + ((seconds) / 60)
    alltarget_minutes = (original_minutes * (target)) / (miles)
    
    frac, whole = math.modf(alltarget_minutes)
    
    target_minutes = int(whole)
    target_seconds = int(frac * 60)
    
    return "Time to run the target distance of {0:.2f} miles is {1} minutes and {2} seconds.".format(target, target_minutes, target_seconds)
    
print_targettime = targettime(float(target), float(miles), int(minutes), int(seconds))

print("\n{0}\n{1}\n{2}".format(print_averagepace, print_averagespeed, print_targettime))
    
