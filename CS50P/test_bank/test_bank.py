from bank import value

def main() :
    test_return_0()
    test_return_20()
    test_return_100()
    ...

def test_return_0():
    assert value('hello') == 0
    assert value("Hello") == 0
    assert value("Hello, world") == 0
    ...

def test_return_20():
    assert value('hi') == 20
    assert value("Hey") == 20
    ...

def test_return_100():
    assert value('morning') == 100
    assert value("whats up") == 100
    ...

if __name__ == "__main__" :
    main()