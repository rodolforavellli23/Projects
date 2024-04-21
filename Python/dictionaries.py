# Chapter 7 - Dictionaries and Sets

bands = {
    "vocals": "Plant",
    "guitar": "Page"
}

bands2 = dict(vocals="Plant", guitar="Page")

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

a = "guitar" in bands
print("{} , guitar in bands = {}".format(bands, a))