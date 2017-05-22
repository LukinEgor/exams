#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
  int number;
  char f_name[50];
  char s_name[50];
  char l_name[50];
  char group[50];
} Student;

typedef struct _Node {
    Student *student;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct _MyList {
    size_t size;
    Node *head;
    Node *tail;
} MyList;

MyList* createMyList() {
    MyList *tmp = (MyList*) malloc(sizeof(MyList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

void deleteMyList(MyList **list) {
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

Node* getNth(MyList *list, size_t index) {
    Node *tmp = list->head;
    size_t i = 0;

    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }

    return tmp;
}

void insert(MyList *list, size_t index, Student *student) {
    Node *elm = NULL;
    Node *ins = NULL;
    elm = getNth(list, index);

    if (list->size == 0) {
      ins = (Node*) malloc(sizeof(Node));
      ins->student = student;
      ins->prev = NULL;
      ins->next = NULL;
      list->head = ins;
      list->tail = ins;
      list->size++;
    } else if (elm == NULL) {
      printf("Failed");
      exit(5);
    } else {
      ins = (Node*) malloc(sizeof(Node));
      ins->student = student;
      ins->prev = elm;
      ins->next = elm->next;
      if (elm->next) {
	elm->next->prev = ins;
      }
      elm->next = ins;

      if (!elm->prev) {
	list->head = elm;
      }
      if (!elm->next) {
	list->tail = elm;
      }

      list->size++;
    }
}

void* deleteNth(MyList *list, size_t index) {
    Node *elm = NULL;
    void *tmp = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->student;

    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }

    free(elm);

    list->size--;

    return tmp;
}

void printStudent(Student *student) {
  printf( "Student - %s %s %s %s, %d :\n", student->f_name, student->s_name, student->l_name, student->group, student->number);
}

void printMyList(MyList *list) {
    Node *tmp = list->head;
    while (tmp) {
	printStudent(tmp->student);
        tmp = tmp->next;
    }
    printf("\n");
}

void addStudent(MyList *list, Student *student, int position) {
  insert(list, position, student);
  printf( "\nSuccess!\n");
}

Student* createStudent() {
  Student *student = (Student*) malloc(sizeof(Student));

  printf( "\nEnter a number of document:\n");
  scanf("%d", &student->number);

  printf( "\nEnter a first name:\n");
  scanf("%s", student->f_name);

  printf( "\nEnter a second name:\n");
  scanf("%s", student->s_name);

  printf( "\nEnter a last name:\n");
  scanf("%s", student->l_name);

  printf( "\nEnter a group:\n");
  scanf("%s", student->group);

  return student;
}

MyList* searchByGroup(MyList *list, char *group) {
  MyList *new_list = (MyList*) malloc(sizeof(MyList));
  Node *tmp = list->head;
  while(tmp) {
    if (strcmp(tmp->student->group, group) == 0) {
      addStudent(new_list, tmp->student, 0);
    }
    tmp = tmp->next;
  }

  return new_list;
}

MyList* searchByFirstLetter(MyList *list, char first_letter) {
  MyList *new_list = (MyList*) malloc(sizeof(MyList));
  Node *tmp = list->head;
  while(tmp) {
    char letter = tmp->student->f_name[0];
    if (letter == first_letter) {
      addStudent(new_list, tmp->student, 0);
    }
    tmp = tmp->next;
  }

  return new_list;
}


int main (void)
{
  MyList *list = (MyList*) malloc(sizeof(MyList));

  while(1) {
    int i;

    printf( "\nEnter a value :\n 1 - Add to start list\n 2 - Print List\n 3 - Add to middle list\n 4 - Search by group\n 5 - Search by name\n 0 - Exit\n");
    scanf("%d", &i);

    if (i == 0) {
      deleteMyList(&list);
      return 0;
    } else if (i == 1) {
      Student *student = createStudent();
      addStudent(list, student, 0);
    } else if (i == 2) {
      printMyList(list);
    } else if (i == 3) {
      Student *student = createStudent();
      int position = list->size / 2;
      addStudent(list, student, position);
    } else if (i == 4) {
      char str[100];
      printf( "\nEnter a group:\n");
      scanf("%s", str);

      MyList *one_group = searchByGroup(list, str);
      printMyList(one_group);
    } else if (i == 5) {
      char str[100];
      printf( "\nEnter first letter:\n");
      scanf("%s", str);

      MyList *one_group = searchByFirstLetter(list, str[0]);
      printMyList(one_group);
    }
  }
}
