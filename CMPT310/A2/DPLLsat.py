#!/usr/bin/python3
# CMPT310 A2
#####################################################
#####################################################
# Please enter the number of hours you spent on this
# assignment here
"""
num_hours_i_spent_on_this_assignment = 
"""
#
#####################################################
#####################################################

#####################################################
#####################################################
# Give one short piece of feedback about the course so far. What
# have you found most interesting? Is there a topic that you had trouble
# understanding? Are there any changes that could improve the value of the
# course to you? (We will anonymize these before reading them.)
"""
<Your feedback goes here>


"""
#####################################################
#####################################################
import sys, getopt
import copy
# import random
# import time
# import numpy as np
sys.setrecursionlimit(10000)

class SatInstance:
    def __init__(self):
        pass

    def from_file(self, inputfile):
        self.clauses = list()
        self.VARS = set()
        self.p = 0
        self.cnf = 0
        with open(inputfile, "r") as input_file:
            self.clauses.append(list())
            maxvar = 0
            for line in input_file:
                tokens = line.split()
                if len(tokens) != 0 and tokens[0] not in ("p", "c"):
                    for tok in tokens:
                        lit = int(tok)
                        maxvar = max(maxvar, abs(lit))
                        if lit == 0:
                            self.clauses.append(list())
                        else:
                            self.clauses[-1].append(lit)
                if tokens[0] == "p":
                    self.p = int(tokens[2])
                    self.cnf = int(tokens[3])
            assert len(self.clauses[-1]) == 0
            self.clauses.pop()
            if (maxvar > self.p):
                print("Non-standard CNF encoding!")
                sys.exit(5)
        # Variables are numbered from 1 to p
        for i in range(1, self.p + 1):
            self.VARS.add(i)

    def __str__(self):
        s = ""
        for clause in self.clauses:
            s += str(clause)
            s += "\n"
        return s


def main(argv):
    inputfile = ''
    verbosity = False
    inputflag = False
    try:
        opts, args = getopt.getopt(argv, "hi:v", ["ifile="])
    except getopt.GetoptError:
        print('DPLLsat.py -i <inputCNFfile> [-v] ')
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print('DPLLsat.py -i <inputCNFfile> [-v]')
            sys.exit()
        ##-v sets the verbosity of informational output
        ## (set to true for output veriable assignments, defaults to false)
        elif opt == '-v':
            verbosity = True
        elif opt in ("-i", "--ifile"):
            inputfile = arg
            inputflag = True
    if inputflag:
        instance = SatInstance()
        instance.from_file(inputfile)
        #start_time = time.time()
        solve_dpll(instance, verbosity)
        #print("--- %s seconds ---" % (time.time() - start_time))

    else:
        print("You must have an input file!")
        print('DPLLsat.py -i <inputCNFfile> [-v]')


# Finds a satisfying assignment to a SAT instance,
# using the DPLL algorithm.
# Input: a SAT instance and verbosity flag
# Output: print "UNSAT" or
#    "SAT"
#    list of true literals (if verbosity == True)
#
#  You will need to define your own
#  DPLLsat(), DPLL(), pure-elim(), propagate-units(), and
#  any other auxiliary functions
def solve_dpll(instance, verbosity):
    # print(instance)
    # instance.VARS goes 1 to N in a dict
    # print(instance.VARS)
    # print(verbosity)
    ###########################################
    # Start your code
    clauses = instance.clauses
    variables = instance.VARS
    assignments = [0] * (len(variables) + 1)
    SAT = DPLLsat(clauses, assignments)
    if SAT == False:
        print("UNSAT")
    else:
        print("SAT")
        if verbosity:
            print(sorted([index for index in range(1, len(SAT[1])) if SAT[1][index] == 1]))


def DPLLsat(clauses, assignments):
    if clauses is None:
        return False
    # clauses = sorted(clauses, key=lambda x: len(x))
    for clause in clauses:
        # if len(clause) > 1:
        #     break
        if len(clause) == 1:
            temp = clause[0]
            if temp > 0:
                if assignments[temp] == -1:
                    return False
                assignments[temp] = 1
            else:
                if assignments[-temp] == 1:
                    return False
                assignments[-temp] = -1
    clauses = DPLL(clauses, assignments)
    if clauses is None:
        return False
    elif len(clauses) == 0:
        return True, assignments
    assignments[abs(clauses[0][0])] = 1
    true_assignments = copy.deepcopy(assignments)
    true_clauses = DPLL(copy.deepcopy(clauses), assignments)
    assignments[abs(clauses[0][0])] = -1
    false_clauses = DPLL(clauses, assignments)
    if true_clauses is None and false_clauses is None:
        return False
    elif true_clauses == []:
        return True, true_assignments
    elif false_clauses == []:
        return True, assignments
    else:
        return DPLLsat(true_clauses, true_assignments) or DPLLsat(false_clauses, assignments)


def DPLL(clauses, assignments):
    if clauses is None:
        return None
    n = len(clauses)
    i = 0
    while i < n:
        for j in range(len(clauses[i])):
            temp = clauses[i][j]
            if assignments[abs(temp)] == 0:
                pass
            elif temp > 0:
                if assignments[temp] == 1:
                    clauses.pop(i)
                    i -= 1
                    n -= 1
                    break
                else:
                    if len(clauses[i]) == 1:
                        return None
                    else:
                        clauses[i].pop(j)
                        break
            else:
                if assignments[-temp] == -1:
                    clauses.pop(i)
                    i -= 1
                    n -= 1
                    break
                else:
                    if len(clauses[i]) == 1:
                        return None
                    else:
                        clauses[i].pop(j)
                        break
        i += 1
    return clauses

    ###########################################
    

if __name__ == "__main__":
    main(sys.argv[1:])
