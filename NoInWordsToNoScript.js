


const wordString = "five one zero two four eight zero double three two";

const wordToNum = (wordString)=> {

    const wordToNumMap = {
        0: 'zero',
        1: 'one',
        2: 'two',
        3: 'three',
        4: 'four',
        5: 'five',
        6: 'six',
        7: 'seven',
        8: 'eight',
        9: 'nine',
    };
    
    const multipiers = {
        2: 'double',
        3: 'triple',
        4: 'quadruple'
    };

    const wordArr = wordString.split(' ');
    // console.log(wordArr);
    const numArr = [];
    // console.log(numArr);

    let count = 1;
    wordArr.forEach(word => {
        if(Object.values(multipiers).includes(word)) {
            count = Object.keys(multipiers).find(key=> word === multipiers[key]);
            // console.log(count);
        }
        else {
            const num = Object.keys(wordToNumMap).find(key=> word === wordToNumMap[key]);
            for(let i=1; i<=count; i++) numArr.push(num);
            count = 1;
        }
    });

    // console.log(numArr);
    return numArr.join('');

};

console.log(wordToNum(wordString));