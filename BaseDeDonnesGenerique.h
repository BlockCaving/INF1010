#ifndef BASE_DE_DONNES_GENERIQUE
#define BASE_DE_DONNES_GENERIQUE

#include <list>
#include <algorithm>
#include <iterator>

// Implementer toutes les methodes dans ce fichier

using namespace  std;
template<typename T, typename S> //T = Image, S = GroupeImage
class BaseDeDonnesGenerique
{
public:
	BaseDeDonnesGenerique();
	~BaseDeDonnesGenerique();

	list<T*> obtenirListImages() const {
		return listImage_;
	};
	list<S*> obtenirListGroupeImages() const {
		return listGroupeImages_;
	};

	void ajouter(T* t) {
		listImage_.push_back(t);
	};
	void ajouter(S* s) {
		listGroupeImages_.push_back(s);
	};

	bool supprimer(const T* t) {
		Iterator pos = listImage_.begin();
		Iterator fin = listImage_.end();
		for (pos; pos != fin; pos++) {
			if (*pos == t) {
				listImage_.erase(pos);
				break;
			}
		}
	};
	bool supprimer(const S* s) {
		Iterator pos = listGroupeImages_.begin();
		Iterator fin = listGroupeImages_.end();
		for (pos; pos != fin; pos++) {
			if (*(*pos) == t) {
				listGroupeImages_.erase(pos);
				break;
			}
		}
	};


	template<typename Predicate>
	bool supprimerImage(const Predicate& predicate) {
		auto it = remove_if(listImage_.begin(), listImage_.end(), predicate);
		listImage_.erase(it, listImage_.end());
	}

	template<typename Predicate>
	bool supprimerGroupeImage(const Predicate& predicate) {
		auto it = remove_if(listGroupImage_.begin(), listGroupImage_.end(), predicate);
		listGroupImage_.erase(it, listGroupImage_.end());
	}

	void vider() {
		listImage_.erase(listImage_.begin(), listImage_.end());
		listGroupImage_.erase(listGroupImage_.begin(), listGroupImage_.end());
	}

	BaseDeDonnesGenerique& operator+=(T* t) {
		ajouter(t);
		return *this;
	}

	BaseDeDonnesGenerique& operator+=(S* s) {
		ajouter(s);
		return *this;
	}

	BaseDeDonnesGenerique& operator-=(T* t) {
		supprimer(t);
		return *this;
	}

	BaseDeDonnesGenerique& operator-=(S* s) {
		supprimer(s);
		return *this;
	}

protected:
	list<T*> listImage_;
	list<S*> listGroupeImage_;
};



#endif
