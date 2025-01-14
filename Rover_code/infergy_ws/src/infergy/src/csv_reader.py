#!/usr/bin/env python3
import csv
with open('nn_data.txt') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    for row in csv_reader:
        for i in range (1,4):
            joint_angles = joint_angles.appendrow[i]