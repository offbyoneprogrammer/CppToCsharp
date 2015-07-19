namespace Vocab
{
    class vocab
    {
        private string english;
        public string German { get; private set; }

        public string English { get { return english; } private set { english = value; } }

        public vocab(string english, string german)
        {
            this.English = english;
            this.German = german;
        }

        public bool compareGerman(string german)
        {
            return German == german;
        }

        public override string ToString()
        {
            return English + " " + German;
        }
    }
}
