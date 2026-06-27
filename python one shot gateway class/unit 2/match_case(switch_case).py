# MATCH CASE IN PYTHON
s= input("enter a number associated with week days:")

match s:
    case s if s == "mon":
        print("monday")
    case "tues":
        print("tuesday")
    case "wed":
        print("wednesday")
    case "thu":
        print("thurusday")
    case "fri":
        print("friday")
    case "sat":
        print("saturdaay")
    case _:
        print("not matched")
        
    
# s = input("enter input for months:")
# a= int(s)
# match a:
#     case 13 | 24 :
#         print("feburary loves july")
        
#     case 2 | 8 :
#         print("birthday months:")
#     case _:
#          print("not valid:")