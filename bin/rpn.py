#!/usr/bin/env python3

import os
import sys

# Globals

OPERATORS = {'+', '-', '*', '/'}

# Functions

def usage(status=0):
    ''' Display usage message and exit with status. '''
    progname = os.path.basename(sys.argv[0])
    print(f'''Usage: {progname}

By default, {progname} will process expressions from standard input.''')
    sys.exit(status)

def error(message):
    ''' Display error message and exit with error. '''
    print(message, file=sys.stderr)
    sys.exit(1)

def evaluate_operation(operation, operand1, operand2):
    ''' Return the result of evaluating the operation with operand1 and
    operand2.

    >>> evaluate_operation('+', 4, 2)
    6

    >>> evaluate_operation('-', 4, 2)
    2

    >>> evaluate_operation('*', 4, 2)
    8

    >>> evaluate_operation('/', 4, 2)
    2.0
    '''
    # OPERATORS IS A SET
    
    if operation in OPERATORS:
        if operation == '+':
            return operand1 + operand2
        elif operation == '-':
            return operand1 - operand2
        elif operation == '/':
            return operand1 / operand2
        elif operation == '*':
            return operand1 * operand2
    else:
        error("invalid operation")

def evaluate_expression(expression):
    ''' Return the result of evaluating the RPN expression.

    >>> evaluate_expression('4 2 +')
    6.0

    >>> evaluate_expression('4 2 -')
    2.0

    >>> evaluate_expression('4 2 *')
    8.0

    >>> evaluate_expression('4 2 /')
    2.0

    >>> evaluate_expression('4 +')
    Traceback (most recent call last):
    ...
    SystemExit: 1

    >>> evaluate_expression('a b +')
    Traceback (most recent call last):
    ...
    SystemExit: 1
    '''
    split_ex = expression.split(' ')
    num = []
    total = 0
    while split_ex:
        try:
            split_ex[0] = float(split_ex[0])
            num.append(split_ex[0])
            split_ex.pop(0)
        except:
            if len(num) >= 2:
                num.append(evaluate_operation(split_ex[0], num[-2], num[-1]))
                num.pop(-2)
                num.pop(-2)
                split_ex.pop(0)
            else:
                error("Incorrect RPN Format\n\t\"Try <operand> <operand> <operation>\"")   
            pass

    return num[0] 

def main():
    ''' Parse command line arguments and process expressions from standard
    input. '''
    arguments = sys.argv[1:]
    
    while arguments and arguments[0].startswith('-'):
        argument = arguments.pop(0)
        if argument == '-h':
            usage(0)
        else:
            usage(1)

    for line in sys.stdin:
        line = line.rstrip()
        print(evaluate_expression(line))
# Main Execution

if __name__ == '__main__':
    main()

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:
