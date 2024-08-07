# Chapter 7 - Dictionaries and Sets

# bands = {
#     "vocals": "Plant",
#     "guitar": "Page"
# }

# bands2 = dict(vocals="Plant", guitar="Page")

# print(bands2)
# print(bands)
# print("There are {} elements".format(len(bands)))
# print(type(bands))


# Accessing items inside a dictionary

# print(bands["guitar"])
# print(bands.get("vocals"))

# Listing Keys & Values

# print(bands.keys())
# print(bands.values())

# Listing a dict as a tuple

# print(bands.items())

# Verify if a key exists

# a = "guitar" in bands
# b = "triangle" in bands

# print("{} , guitar in bands = {}, triangle in bands = {}".format(bands, a, b))

# Change or add values in a dict

# bands["vocals"] = "Coverdale"
# bands.update({"bass": "JPJ"})
# print(bands)

# Removing items

# print(bands.pop("bass"))
# print(bands)

# bands["drums"] = "Bonham"

# print(bands)
# print(bands.popitem()) # Tuple
# print(bands)

# Delete and clear

# print(bands)

# del bands["drums"]

# print(bands)

# bands2.clear()

# print(bands2)

# del bands2

# Copying dictionaries

# bands2 = bands.copy()

# bands2["drums"] = "Dave"

# print(bands2)

# Copying using the contructor function

# bands3 = dict(bands)    

# print(bands3)

# Nested dictionaries

# member1 = {
#     "name": "Plant",
#     "instrument": "vocals"
# }
# member2 = {
#     "name": "Page",
#     "instrument": "guitar"
# }
# member3 = {
#     "name": "Bonham",
#     "instrument": "drums"
# }

# band = {
#     "first member": member1, 
#     "second member": member2, 
#     "third member": member3
# }

# print(band["first member"]["name"])


# Sets in python

nums = {1, 2, 3, 4} 

nums2 = set((1,2,3,4))

# print(nums)
# print(nums2)
# print(type(nums))
# print("There are {} items in this set.".format(len(nums)))

nums3 = {0,False,1,True}
# print("{} , Note: sets don't allow for dublicate elements to be inside them".format(nums3))

# Check if a value is in a set

a = 2 in nums
print("2 in nums = {}".format(a))

# Add elements to a set

nums.add(8)
print(nums)

# Add elements from another set

morenums = {5, 6, 7}
nums.update(morenums)
print(nums)

# Merge sets

one = {1,2,3}
two = {4,5,6}

newMerged = one.union(two)

print(newMerged)