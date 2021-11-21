
from datetime import date
from model import Person, Pet

uncle_bob = Person(name='Bob', birthday=date(1960, 1, 15))
uncle_bob.save() # bob is now stored in the database
# Returns: 1

grandma = Person.create(name='Grandma', birthday=date(1935, 3, 1))

bob_kitty = Pet.create(owner=uncle_bob, name='Kitty', animal_type='cat')

grandma = Person.get(Person.name == 'Grandma')

# print(grandma.name)

# for person in Person.select():
#     print(person.name)

# query = Pet.select().where(Pet.animal_type == 'cat')
# for pet in query:
#     print(pet.name, pet.owner.name)

query = (Pet
         .select(Pet, Person)
         .join(Person)
         .where(Pet.animal_type == 'cat'))

for pet in query:
    print(pet.name, pet.owner.name)




